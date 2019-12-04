################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Exception.c \
../Src/gpio.c \
../Src/main.c \
../Src/nvic.c \
../Src/rcc.c \
../Src/spi.c \
../Src/stateMachine.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/timer.c 

OBJS += \
./Src/Exception.o \
./Src/gpio.o \
./Src/main.o \
./Src/nvic.o \
./Src/rcc.o \
./Src/spi.o \
./Src/stateMachine.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/timer.o 

C_DEPS += \
./Src/Exception.d \
./Src/gpio.d \
./Src/main.d \
./Src/nvic.d \
./Src/rcc.d \
./Src/spi.d \
./Src/stateMachine.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx -I"C:/stm32_programming_practice/peripheralsV2/Inc" -I"C:/stm32_programming_practice/peripheralsV2/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/stm32_programming_practice/peripheralsV2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/stm32_programming_practice/peripheralsV2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/stm32_programming_practice/peripheralsV2/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


