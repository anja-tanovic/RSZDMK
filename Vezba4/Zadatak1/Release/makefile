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
Zadatak1.lss \

FLASH_IMAGE += \
Zadatak1.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Zadatak1.elf secondary-outputs

# Tool invocations
Zadatak1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Zadatak1.map -L"D:\ANJA\Anja\3.godina\2.semestar\Razvoj softvera za digitalne mikrokontrolere\Vezbe\4 organizacija u biblioteke\pin_driver\Release" -L"D:\ANJA\Anja\3.godina\2.semestar\Razvoj softvera za digitalne mikrokontrolere\Vezbe\4 organizacija u biblioteke\timer_0\Release" -mmcu=atmega328p -o "Zadatak1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Zadatak1.lss: Zadatak1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Zadatak1.elf  >"Zadatak1.lss"
	@echo 'Finished building: $@'
	@echo ' '

Zadatak1.hex: Zadatak1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Zadatak1.elf  "Zadatak1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Zadatak1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Zadatak1.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Zadatak1.elf
	@echo 'Invoking: AVRDude'
	C:\Users\VTS-zaposleni\Downloads\NE BRISATI\eclipse\bin\avrdude -pm328p -carduino -PCOM3 -Uflash:w:Zadatak1.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Zadatak1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
