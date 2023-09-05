################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HDCMOTOR_program.c \
../HLED_program.c \
../HSERVO_program.c \
../HSSD_program.c \
../HSTEPPER_program.c \
../MDIO_program.c \
../MGIE_program.c \
../MSPI_program.c \
../MTIMER_program.c \
../MUSART_program.c \
../Slave.c 

OBJS += \
./HDCMOTOR_program.o \
./HLED_program.o \
./HSERVO_program.o \
./HSSD_program.o \
./HSTEPPER_program.o \
./MDIO_program.o \
./MGIE_program.o \
./MSPI_program.o \
./MTIMER_program.o \
./MUSART_program.o \
./Slave.o 

C_DEPS += \
./HDCMOTOR_program.d \
./HLED_program.d \
./HSERVO_program.d \
./HSSD_program.d \
./HSTEPPER_program.d \
./MDIO_program.d \
./MGIE_program.d \
./MSPI_program.d \
./MTIMER_program.d \
./MUSART_program.d \
./Slave.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


