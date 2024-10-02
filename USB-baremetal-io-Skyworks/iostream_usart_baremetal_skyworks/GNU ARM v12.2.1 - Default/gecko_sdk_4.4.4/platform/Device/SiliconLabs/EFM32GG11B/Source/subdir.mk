################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/startup_efm32gg11b.c \
../gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.c 

OBJS += \
./gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/startup_efm32gg11b.o \
./gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.o 

C_DEPS += \
./gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/startup_efm32gg11b.d \
./gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/startup_efm32gg11b.o: ../gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/startup_efm32gg11b.c gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\driver\configuration_over_swo\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\driver\debug\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\iostream\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/startup_efm32gg11b.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.o: ../gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.c gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\driver\configuration_over_swo\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\driver\debug\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\iostream\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


