################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TestAvrProject_Slave.lss \

FLASH_IMAGE += \
TestAvrProject_Slave.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TestAvrProject_Slave.elf secondary-outputs

# Tool invocations
TestAvrProject_Slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TestAvrProject_Slave.map -mmcu=atmega32 -o "TestAvrProject_Slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TestAvrProject_Slave.lss: TestAvrProject_Slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TestAvrProject_Slave.elf  >"TestAvrProject_Slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

TestAvrProject_Slave.hex: TestAvrProject_Slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TestAvrProject_Slave.elf  "TestAvrProject_Slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TestAvrProject_Slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TestAvrProject_Slave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TestAvrProject_Slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
