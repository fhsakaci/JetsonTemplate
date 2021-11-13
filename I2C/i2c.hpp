/*
 * i2c.hpp
 *
 *  Created on: Nov 12, 2021
 *      Author: sakaci
 */

#ifndef I2C_I2C_HPP_
#define I2C_I2C_HPP_

#include <logger/inc/LoggerCpp.h>


// standard mode: 100 kbit/s, full speed: 400 kbit/s, fast mode: 1 mbit/s, high speed: 3,2 Mbit/s
enum speed_mode {
	standard = 100000,
	full = 400000,
	fast = 1000000,
	high = 3200000
};

class i2c {
public:
	i2c(int sda, int scl);
	bool set_speed(speed_mode speed);
	int get_speed(void);
	int send(char*);

private:
	int sda;
	int scl;
	int speed;
};





#endif /* I2C_I2C_HPP_ */
