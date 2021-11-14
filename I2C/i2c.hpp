/*
 * i2c.hpp
 *
 *  Created on: Nov 12, 2021
 *      Author: sakaci
 */

#ifndef I2C_I2C_HPP_
#define I2C_I2C_HPP_

#include <logger/inc/LoggerCpp.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>


// standard mode: 100 kbit/s, full speed: 400 kbit/s, fast mode: 1 mbit/s, high speed: 3,2 Mbit/s
enum speed_mode {
	standard = 100000,
	full = 400000,
	fast = 1000000,
	high = 3200000
};

enum communication_mode {
	master,
	slave
};

class i2c {
public:
	i2c(char*);
	bool set_speed(speed_mode speed);
	int get_speed(void);
	bool set_communication_mode(communication_mode mode);
	int get_comminication_mode(void);
	unsigned char* request(uint8_t address, uint8_t* message);

private:
	char* bus_name;
	int speed;
	int mode;
	Log::Logger mLogger;
	int i2c_fd;
	struct i2c_rdwr_ioctl_data msgset;
	struct i2c_msg iomsgs[2];

};





#endif /* I2C_I2C_HPP_ */
