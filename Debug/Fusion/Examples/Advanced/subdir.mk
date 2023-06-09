################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fusion/Examples/Advanced/main.c 

OBJS += \
./Fusion/Examples/Advanced/main.o 

C_DEPS += \
./Fusion/Examples/Advanced/main.d 


# Each subdirectory must supply rules for building sources it contributes
Fusion/Examples/Advanced/%.o Fusion/Examples/Advanced/%.su Fusion/Examples/Advanced/%.cyclo: ../Fusion/Examples/Advanced/%.c Fusion/Examples/Advanced/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/Fusion/Fusion -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS3MDL-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/I3G4250D-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS331DLH-PID -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Fusion-2f-Examples-2f-Advanced

clean-Fusion-2f-Examples-2f-Advanced:
	-$(RM) ./Fusion/Examples/Advanced/main.cyclo ./Fusion/Examples/Advanced/main.d ./Fusion/Examples/Advanced/main.o ./Fusion/Examples/Advanced/main.su

.PHONY: clean-Fusion-2f-Examples-2f-Advanced

