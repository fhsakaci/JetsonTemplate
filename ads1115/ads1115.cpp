/*
 * adc.cpp
 *
 *  Created on: Nov 26, 2021
 *      Author: sakaci
 */

#include "ads1115/ads1115.hpp"
#include <unistd.h>

ads1115::ads1115(char* bus_name, int address):mLogger("ads1115")
{
	mLogger.info() << "ADS1115 bus opening";
	this->i2c_object = i2c(bus_name, address);
}

void ads1115::init(void)
{

}

float ads1115::read_channel(channel adc_channel)
{
    char config[3] = {0};
	config[0] = 0x01;
	config[1] = 0x84 + adc_channel*0x10;
	config[2] = 0x83;
	this->i2c_object.write_data(3, config);
	//usleep(1);
	char reg[1] = {0x00};
	this->i2c_object.read_data(reg, 2);

}

void ads1115::operator()(int x)
{
	while(1)
	{
		this->read_channel(channel::one);
		sleep(1);
	}
}
