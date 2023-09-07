################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXT_INT/EXT_INT.c \
../MCAL/EXT_INT/GIE.c 

OBJS += \
./MCAL/EXT_INT/EXT_INT.o \
./MCAL/EXT_INT/GIE.o 

C_DEPS += \
./MCAL/EXT_INT/EXT_INT.d \
./MCAL/EXT_INT/GIE.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXT_INT/%.o: ../MCAL/EXT_INT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


