/*
 * i2c.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: sakaci
 */

#ifndef I2C_I2C_CPP_
#define I2C_I2C_CPP_

#include <I2C/i2c.hpp>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

i2c::i2c():mLogger("I2C")
{

}

i2c::i2c(char* bus_name, int addr):mLogger("I2C")
{
	mLogger.info() << "I2C bus opening";
	this->bus_name = bus_name;
	this->speed = speed_mode::fast;
	this->mode = communication_mode::master;
	if ((this->i2c_fd = open("/dev/i2c-1", O_RDWR)) < 0)
	{
		mLogger.error() << "Failed to open the bus. \n";
		exit(1);
	}
	ioctl(this->i2c_fd, I2C_SLAVE, 0x48);
}

bool i2c::set_speed(speed_mode speed)
{
	try{
		this->speed = speed;
		return true;
	}
	catch (int myNum) {
		return false;
	}

}

int i2c::get_speed(void)
{
	return this->speed;
}

bool i2c::set_communication_mode(communication_mode mode)
{
	try{
		this->mode = mode;
		return true;
	}
	catch (int myNum) {
		return false;
	}

}

int i2c::get_comminication_mode(void)
{
	return this->mode;
}

void i2c::write_data(int size, char config[])
{
	//char config[3] = {0};
	//config[0] = 0x01;
	//config[1] = 0x84;
	//config[2] = 0x83;
	write(this->i2c_fd, config, 3);

}

char* i2c::read_data(char reg[], int size)
{
	//char reg[1] = {0x00};
	write(this->i2c_fd, reg, 1);
	char data[size]={0};
	if(read(this->i2c_fd, data, size) != size)
	{
		mLogger.error() << "Input/Output Error \n";
		exit(1);
	}
	else
	{
		int raw_adc = (data[0] * 256 + data[1]);
		if (raw_adc > 32767)
		{
			raw_adc -= 65535;
		}
		mLogger.debug() << raw_adc;
		return data;
	}

}


uint8_t* i2c::request(uint8_t address, uint8_t* message)
{
	uint8_t rbuf[1];
	iomsgs[0].addr = address;
	/*write*/
	iomsgs[0].flags = 0;
	iomsgs[0].buf = message;
	iomsgs[0].len = 1;

	iomsgs[1].addr = address;
	/*read*/
	iomsgs[1].flags = I2C_M_RD;
	iomsgs[1].buf = rbuf;
	iomsgs[1].len= 1;

	msgset.msgs = iomsgs;
	msgset.nmsgs = 2;

	int rc;
	rc = ioctl(i2c_fd, I2C_RDWR, &msgset);
	if (rc < 0) {
	    perror("ioctl I2C_RDWR");
	    exit(0);
	}
	return rbuf;
}


#endif /* I2C_I2C_CPP_ */
