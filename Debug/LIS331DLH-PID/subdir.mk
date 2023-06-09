################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIS331DLH-PID/lis331dlh_reg.c 

OBJS += \
./LIS331DLH-PID/lis331dlh_reg.o 

C_DEPS += \
./LIS331DLH-PID/lis331dlh_reg.d 


# Each subdirectory must supply rules for building sources it contributes
LIS331DLH-PID/%.o LIS331DLH-PID/%.su LIS331DLH-PID/%.cyclo: ../LIS331DLH-PID/%.c LIS331DLH-PID/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS3MDL-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/I3G4250D-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS331DLH-PID -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LIS331DLH-2d-PID

clean-LIS331DLH-2d-PID:
	-$(RM) ./LIS331DLH-PID/lis331dlh_reg.cyclo ./LIS331DLH-PID/lis331dlh_reg.d ./LIS331DLH-PID/lis331dlh_reg.o ./LIS331DLH-PID/lis331dlh_reg.su

.PHONY: clean-LIS331DLH-2d-PID

