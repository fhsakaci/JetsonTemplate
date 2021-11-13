################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../logger/src/Config.cpp \
../logger/src/DateTime.cpp \
../logger/src/Log.cpp \
../logger/src/Logger.cpp \
../logger/src/Manager.cpp \
../logger/src/OutputConsole.cpp \
../logger/src/OutputDebug.cpp \
../logger/src/OutputFile.cpp \
../logger/src/OutputSyslog.cpp 

OBJS += \
./logger/src/Config.o \
./logger/src/DateTime.o \
./logger/src/Log.o \
./logger/src/Logger.o \
./logger/src/Manager.o \
./logger/src/OutputConsole.o \
./logger/src/OutputDebug.o \
./logger/src/OutputFile.o \
./logger/src/OutputSyslog.o 

CPP_DEPS += \
./logger/src/Config.d \
./logger/src/DateTime.d \
./logger/src/Log.d \
./logger/src/Logger.d \
./logger/src/Manager.d \
./logger/src/OutputConsole.d \
./logger/src/OutputDebug.d \
./logger/src/OutputFile.d \
./logger/src/OutputSyslog.d 


# Each subdirectory must supply rules for building sources it contributes
logger/src/%.o: ../logger/src/%.cpp logger/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	aarch64-linux-gnu-g++ -I"C:\Users\Administrator\Documents\GitHub\JetsonTemplate" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


