################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Drivetrain.cpp \
../src/FilteredGamepad.cpp \
../src/GamepadL.cpp \
../src/Trever.cpp 

OBJS += \
./src/Drivetrain.o \
./src/FilteredGamepad.o \
./src/GamepadL.o \
./src/Trever.o 

CPP_DEPS += \
./src/Drivetrain.d \
./src/FilteredGamepad.d \
./src/GamepadL.d \
./src/Trever.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Thunder cRIO Tools C++ Compiler'
	powerpc-wrs-vxworks-g++ -DCPU=PPC603 -DTOOL_FAMILY=gnu -DTOOL=gnu -D_WRS_KERNEL -I"C:\Users\evanp\workspace\Trever\include" -I"C:\Program Files (x86)\FRC_Toolchain\mingw\powerpc-wrs-vxworks\wind_base\/../include/WPILib" -O0 -g3 -Wall -c -fmessage-length=0 -mcpu=603 -mstrict-align -mlongcall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


