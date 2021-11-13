################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../I2C/i2c.cpp 

OBJS += \
./I2C/i2c.o 

CPP_DEPS += \
./I2C/i2c.d 


# Each subdirectory must supply rules for building sources it contributes
I2C/%.o: ../I2C/%.cpp I2C/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	aarch64-linux-gnu-g++ -I"C:\Users\Administrator\Documents\GitHub\JetsonTemplate" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


