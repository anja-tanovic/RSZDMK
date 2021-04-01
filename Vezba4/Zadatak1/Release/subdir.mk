################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc_utils.c \
../logic_utils.c \
../main.c \
../rand_mto.c \
../rand_otm.c 

OBJS += \
./adc_utils.o \
./logic_utils.o \
./main.o \
./rand_mto.o \
./rand_otm.o 

C_DEPS += \
./adc_utils.d \
./logic_utils.d \
./main.d \
./rand_mto.d \
./rand_otm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


