################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../EEPROM_program.c \
../HKPD_program.c \
../HLCD_program.c \
../MAPPING_program.c \
../MDIO_program.c \
../MGIE_program.c \
../MSPI_program.c \
../MTIMER_program.c \
../MTWI_program.c \
../MUSART_program.c \
../Master.c 

OBJS += \
./ADC_program.o \
./EEPROM_program.o \
./HKPD_program.o \
./HLCD_program.o \
./MAPPING_program.o \
./MDIO_program.o \
./MGIE_program.o \
./MSPI_program.o \
./MTIMER_program.o \
./MTWI_program.o \
./MUSART_program.o \
./Master.o 

C_DEPS += \
./ADC_program.d \
./EEPROM_program.d \
./HKPD_program.d \
./HLCD_program.d \
./MAPPING_program.d \
./MDIO_program.d \
./MGIE_program.d \
./MSPI_program.d \
./MTIMER_program.d \
./MTWI_program.d \
./MUSART_program.d \
./Master.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


