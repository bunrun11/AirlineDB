################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AirlineDB.cpp \
../src/Flight.cpp \
../src/FlightManager.cpp \
../src/Person.cpp 

OBJS += \
./src/AirlineDB.o \
./src/Flight.o \
./src/FlightManager.o \
./src/Person.o 

CPP_DEPS += \
./src/AirlineDB.d \
./src/Flight.d \
./src/FlightManager.d \
./src/Person.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


