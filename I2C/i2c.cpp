/*
 * i2c.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: sakaci
 */

#ifndef I2C_I2C_CPP_
#define I2C_I2C_CPP_

#include <I2C/i2c.hpp>

i2c::i2c(int sda, int scl)
{
	Log::Logger logger("I2C.Example");
	logger.warning() << "NO logs before configure()";
	this->scl = scl;
	this->sda = sda;
	speed_mode test;
	this->speed = speed_mode::fast;
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



#endif /* I2C_I2C_CPP_ */
