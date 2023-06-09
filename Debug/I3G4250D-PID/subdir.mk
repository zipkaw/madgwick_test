################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../I3G4250D-PID/i3g4250d_reg.c 

OBJS += \
./I3G4250D-PID/i3g4250d_reg.o 

C_DEPS += \
./I3G4250D-PID/i3g4250d_reg.d 


# Each subdirectory must supply rules for building sources it contributes
I3G4250D-PID/%.o I3G4250D-PID/%.su I3G4250D-PID/%.cyclo: ../I3G4250D-PID/%.c I3G4250D-PID/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/Fusion/Fusion -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS3MDL-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/I3G4250D-PID -I/home/plantator/STM32CubeIDE/workspace_1.12.1/madgwick_test/LIS331DLH-PID -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-I3G4250D-2d-PID

clean-I3G4250D-2d-PID:
	-$(RM) ./I3G4250D-PID/i3g4250d_reg.cyclo ./I3G4250D-PID/i3g4250d_reg.d ./I3G4250D-PID/i3g4250d_reg.o ./I3G4250D-PID/i3g4250d_reg.su

.PHONY: clean-I3G4250D-2d-PID

