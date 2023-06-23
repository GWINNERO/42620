################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/30010_io.c \
../Src/GameScreen.c \
../Src/Joystick.c \
../Src/LED.c \
../Src/ansi_S.c \
../Src/main.c \
../Src/rocet.c \
../Src/screen.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f30x.c \
../Src/timer.c 

OBJS += \
./Src/30010_io.o \
./Src/GameScreen.o \
./Src/Joystick.o \
./Src/LED.o \
./Src/ansi_S.o \
./Src/main.o \
./Src/rocet.o \
./Src/screen.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f30x.o \
./Src/timer.o 

C_DEPS += \
./Src/30010_io.d \
./Src/GameScreen.d \
./Src/Joystick.d \
./Src/LED.d \
./Src/ansi_S.d \
./Src/main.d \
./Src/rocet.d \
./Src/screen.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f30x.d \
./Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DNUCLEO_F302R8 -DDEBUG -DUSE_STDPERIPH_DRIVER=1 -c -I"C:/Users/Emilo/OneDrive/Skrivebord/Game/SPL/inc" -I"C:/Users/Emilo/OneDrive/Skrivebord/Game/Inc" -I"C:/Users/Emilo/OneDrive/Skrivebord/Game/cmsis" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
<<<<<<< Updated upstream
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/GameScreen.d ./Src/GameScreen.o ./Src/Joystick.d ./Src/Joystick.o ./Src/LED.d ./Src/LED.o ./Src/ansi_S.d ./Src/ansi_S.o ./Src/main.d ./Src/main.o ./Src/rocet.d ./Src/rocet.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o ./Src/timer.d ./Src/timer.o
=======
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/GameScreen.d ./Src/GameScreen.o ./Src/Joystick.d ./Src/Joystick.o ./Src/LCD.d ./Src/LCD.o ./Src/LCDgameplay.d ./Src/LCDgameplay.o ./Src/LED.d ./Src/LED.o ./Src/ansi_S.d ./Src/ansi_S.o ./Src/astroid.d ./Src/astroid.o ./Src/buzzer.d ./Src/buzzer.o ./Src/charset.d ./Src/charset.o ./Src/main.d ./Src/main.o ./Src/menu.d ./Src/menu.o ./Src/rocet.d ./Src/rocet.o ./Src/screen.d ./Src/screen.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o ./Src/timer.d ./Src/timer.o ./Src/window.d ./Src/window.o
>>>>>>> Stashed changes

.PHONY: clean-Src

