################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_4.4.4/platform/service/system/src/sl_system_init.c \
../gecko_sdk_4.4.4/platform/service/system/src/sl_system_kernel.c 

OBJS += \
./gecko_sdk_4.4.4/platform/service/system/src/sl_system_init.o \
./gecko_sdk_4.4.4/platform/service/system/src/sl_system_kernel.o 

C_DEPS += \
./gecko_sdk_4.4.4/platform/service/system/src/sl_system_init.d \
./gecko_sdk_4.4.4/platform/service/system/src/sl_system_kernel.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.4/platform/service/system/src/sl_system_init.o: ../gecko_sdk_4.4.4/platform/service/system/src/sl_system_init.c gecko_sdk_4.4.4/platform/service/system/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DUSBD_CFG_MS_OS_DESC_EN=1' '-DGECKO_DEVICE_CLASS_VENDOR_DESCRIPTION_PROPERTY_LEN=64' '-DSL_USBD_VENDOR_MS_EXTENDED_PROPERTIES_QUANTITY=2' '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\CMSIS\RTOS2\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\third_party\freertos\cmsis\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\third_party\freertos\kernel\include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\third_party\freertos\kernel\portable\GCC\ARM_CM4F" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\silicon_labs\silabs_core\memory_manager" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\service\udelay\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\protocol\usb\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\protocol\usb\src" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -fshort-wchar -MMD -MP -MF"gecko_sdk_4.4.4/platform/service/system/src/sl_system_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.4/platform/service/system/src/sl_system_kernel.o: ../gecko_sdk_4.4.4/platform/service/system/src/sl_system_kernel.c gecko_sdk_4.4.4/platform/service/system/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DUSBD_CFG_MS_OS_DESC_EN=1' '-DGECKO_DEVICE_CLASS_VENDOR_DESCRIPTION_PROPERTY_LEN=64' '-DSL_USBD_VENDOR_MS_EXTENDED_PROPERTIES_QUANTITY=2' '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\CMSIS\RTOS2\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\third_party\freertos\cmsis\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\third_party\freertos\kernel\include" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\third_party\freertos\kernel\portable\GCC\ARM_CM4F" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\util\silicon_labs\silabs_core\memory_manager" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\platform\service\udelay\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\protocol\usb\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-simple-WinUSB-Skyworks\gecko_sdk_4.4.4\protocol\usb\src" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -fshort-wchar -MMD -MP -MF"gecko_sdk_4.4.4/platform/service/system/src/sl_system_kernel.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


