/*
 * i2c.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: sakaci
 */

#ifndef I2C_I2C_CPP_
#define I2C_I2C_CPP_

#include <I2C/i2c.hpp>
#include <fcntl.h>


i2c::i2c(char* bus_name):	mLogger("I2C")
{
	mLogger.info() << "I2C bus opening";
	this->bus_name = bus_name;
	this->speed = speed_mode::fast;
	this->mode = communication_mode::master;
	this->i2c_fd = open(bus_name, O_RDWR);
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
