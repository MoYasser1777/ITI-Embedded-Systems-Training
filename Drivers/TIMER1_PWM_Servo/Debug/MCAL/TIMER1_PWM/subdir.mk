################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER1_PWM/TIMER1_PWM.c 

OBJS += \
./MCAL/TIMER1_PWM/TIMER1_PWM.o 

C_DEPS += \
./MCAL/TIMER1_PWM/TIMER1_PWM.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER1_PWM/%.o: ../MCAL/TIMER1_PWM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


