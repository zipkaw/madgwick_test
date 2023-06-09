################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fusion/Python/Python-C-API/imufusion.c 

OBJS += \
./Fusion/Python/Python-C-API/imufusion.o 

C_DEPS += \
./Fusion/Python/Python-C-API/imufusion.d 


# Each subdirectory must supply rules for building sources it contributes
Fusion/Python/Python-C-API/%.o Fusion/Python/Python-C-API/%.su Fusion/Python/Python-C-API/%.cyclo: ../Fusion/Python/Python-C-API/%.c Fusion/Python/Python-C-API/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/Fusion/Fusion -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS3MDL-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/I3G4250D-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS331DLH-PID -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Fusion-2f-Python-2f-Python-2d-C-2d-API

clean-Fusion-2f-Python-2f-Python-2d-C-2d-API:
	-$(RM) ./Fusion/Python/Python-C-API/imufusion.cyclo ./Fusion/Python/Python-C-API/imufusion.d ./Fusion/Python/Python-C-API/imufusion.o ./Fusion/Python/Python-C-API/imufusion.su

.PHONY: clean-Fusion-2f-Python-2f-Python-2d-C-2d-API

