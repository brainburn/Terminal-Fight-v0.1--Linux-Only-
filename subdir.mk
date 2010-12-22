################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../chasm.cpp \
../crystals.cpp \
../enemy.cpp \
../entity.cpp \
../floor.cpp \
../friend.cpp \
../game.cpp \
../main.cpp \
../map.cpp \
../mygetch.cpp \
../player.cpp \
../potion.cpp \
../swarm.cpp \
../tools.cpp \
../unit.cpp \
../wall.cpp \
../weapon.cpp 

OBJS += \
./chasm.o \
./crystals.o \
./enemy.o \
./entity.o \
./floor.o \
./friend.o \
./game.o \
./main.o \
./map.o \
./mygetch.o \
./player.o \
./potion.o \
./swarm.o \
./tools.o \
./unit.o \
./wall.o \
./weapon.o 

CPP_DEPS += \
./chasm.d \
./crystals.d \
./enemy.d \
./entity.d \
./floor.d \
./friend.d \
./game.d \
./main.d \
./map.d \
./mygetch.d \
./player.d \
./potion.d \
./swarm.d \
./tools.d \
./unit.d \
./wall.d \
./weapon.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0  -lncurses -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


