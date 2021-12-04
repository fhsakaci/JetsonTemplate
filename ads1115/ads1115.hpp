/*
 * adc.h
 *
 *  Created on: Nov 26, 2021
 *      Author: sakaci
 */

#ifndef ADS1115_ADS1115_HPP_
#define ADS1115_ADS1115_HPP_

#include "I2C/i2c.hpp"
#include <logger/inc/LoggerCpp.h>
#include <thread>

enum channel {
	one,
	second,
	third,
	fourth
};

class ads1115 {
public:
	ads1115(char*, int);
	void init(void);
	float read_channel(channel);
	void operator()(int);

private:
	Log::Logger mLogger;
	i2c i2c_object;

};



#endif /* ADS1115_ADS1115_HPP_ */
