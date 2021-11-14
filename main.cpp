/*
 * main.cpp
 *
 *  Created on: Nov 11, 2021
 *      Author: sakaci
 */

#include <iostream>
#include <thread>
#include "logger/inc/LoggerCpp.h"
#include "I2C/i2c.hpp"

using namespace std;

class Tester {
public:
    Tester() :
        mLogger("main.Tester")
    {
    }

    void constTest (void) const {
        mLogger.debug() << "log within a const method";
    }

private:
    Log::Logger mLogger; ///< A named logger to produce log
};

int main ()
{

    // Configure the Output objects
    Log::Config::Vector configList;
    Log::Config::addOutput(configList, "OutputConsole");
    Log::Config::addOutput(configList, "OutputFile");
    Log::Config::setOption(configList, "filename",          "log.txt");
    Log::Config::setOption(configList, "filename_old",      "log.old.txt");
    Log::Config::setOption(configList, "max_startup_size",  "0");
    Log::Config::setOption(configList, "max_size",          "10000");

    // Create a Logger object, using a "Main.Example" Channel
    Log::Logger logger("Main.Example");
    logger.warning() << "NO logs before configure()";

    try
    {
        // Configure the Log Manager (create the Output objects)
        Log::Manager::configure(configList);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }

    // Test outputs of various kind of variables, and some common stream manipulations.
    std::string     str("string");
    unsigned int    ui  = 123;
    double          dbl = -0.023f;
    logger.debug() << "Variables ; '" << str << "', '" << ui << "', '" << dbl << "'";
    logger.debug() << "Hexa = " << std::hex << 0x75af0 << " test";
    logger.debug() << "Deci = " << std::right << std::setfill('0') << std::setw(8) << 76035 << " test";
    logger.debug() << "sizeof(logger)=" << sizeof(logger);

    i2c test("/dev/i2c-0");
    test.set_speed(speed_mode::standard);
    test.set_communication_mode(communication_mode::master);
    cout << test.get_speed();
    uint8_t test1=0x20;
    uint8_t	test2[1];
    test2[0] = 0x20;
    test.request(test1, test2);

    return 0;
}
