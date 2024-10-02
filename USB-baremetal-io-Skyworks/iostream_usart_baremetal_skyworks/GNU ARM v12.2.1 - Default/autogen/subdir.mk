################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/sl_board_default_init.c \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c \
../autogen/sl_iostream_handles.c \
../autogen/sl_iostream_init_usart_instances.c 

OBJS += \
./autogen/sl_board_default_init.o \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o \
./autogen/sl_iostream_handles.o \
./autogen/sl_iostream_init_usart_instances.o 

C_DEPS += \
./autogen/sl_board_default_init.d \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d \
./autogen/sl_iostream_handles.d \
./autogen/sl_iostream_init_usart_instances.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/sl_board_default_init.o: ../autogen/sl_board_default_init.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\driver\configuration_over_swo\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\driver\debug\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\iostream\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_board_default_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\driver\configuration_over_swo\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\driver\debug\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\iostream\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\driver\configuration_over_swo\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\driver\debug\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\iostream\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_handles.o: ../autogen/sl_iostream_handles.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\driver\configuration_over_swo\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\driver\debug\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\iostream\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_handles.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_init_usart_instances.o: ../autogen/sl_iostream_init_usart_instances.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32GG11B820F2048GL192=1' '-DHFXO_FREQ=50000000' '-DSL_BOARD_NAME="BRD2204C"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\config" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\autogen" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG11B\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\board\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\hardware\driver\configuration_over_swo\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\driver\debug\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\emlib\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\iostream\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"E:\GitHub\Silabs-GG11-USB\USB-baremetal-io-Skyworks\iostream_usart_baremetal_skyworks\gecko_sdk_4.4.4\platform\service\system\inc" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_init_usart_instances.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

