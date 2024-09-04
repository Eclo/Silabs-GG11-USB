################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.4.4/util/third_party/freertos/kernel/portable/MemMang/subdir.mk
-include gecko_sdk_4.4.4/util/third_party/freertos/kernel/portable/GCC/ARM_CM4F/subdir.mk
-include gecko_sdk_4.4.4/util/third_party/freertos/kernel/subdir.mk
-include gecko_sdk_4.4.4/util/third_party/freertos/cmsis/Source/subdir.mk
-include gecko_sdk_4.4.4/util/silicon_labs/silabs_core/memory_manager/subdir.mk
-include gecko_sdk_4.4.4/protocol/usb/src/subdir.mk
-include gecko_sdk_4.4.4/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.4.4/platform/service/system/src/subdir.mk
-include gecko_sdk_4.4.4/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.4.4/platform/emlib/src/subdir.mk
-include gecko_sdk_4.4.4/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.4.4/platform/common/src/subdir.mk
-include gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/subdir.mk
-include gecko_sdk_4.4.4/platform/CMSIS/RTOS2/Source/subdir.mk
-include gecko_sdk_4.4.4/hardware/board/src/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := usb_device_cdc_acm_freertos_4
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: usb_device_cdc_acm_freertos_4.axf

# Tool invocations
usb_device_cdc_acm_freertos_4.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "E:\GitHub\Silabs-GG11-USB\USB-CDC-Skyworks\autogen\linkerfile.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="usb_device_cdc_acm_freertos_4.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o usb_device_cdc_acm_freertos_4.axf -Wl,--start-group "./app.o" "./main.o" "./usb_cdc_acm_app.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_usbd_class_cdc_acm_instances.o" "./autogen/sl_usbd_configuration_instances.o" "./autogen/sl_usbd_init.o" "./gecko_sdk_4.4.4/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.4.4/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.4.4/platform/CMSIS/RTOS2/Source/os_systick.o" "./gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/startup_efm32gg11b.o" "./gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.o" "./gecko_sdk_4.4.4/platform/common/src/sl_assert.o" "./gecko_sdk_4.4.4/platform/common/src/sl_string.o" "./gecko_sdk_4.4.4/platform/common/src/sl_syscalls.o" "./gecko_sdk_4.4.4/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.4.4/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.4.4/platform/emlib/src/em_core.o" "./gecko_sdk_4.4.4/platform/emlib/src/em_emu.o" "./gecko_sdk_4.4.4/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.4.4/platform/emlib/src/em_msc.o" "./gecko_sdk_4.4.4/platform/emlib/src/em_system.o" "./gecko_sdk_4.4.4/platform/service/device_init/src/sl_device_init_dcdc_s1.o" "./gecko_sdk_4.4.4/platform/service/device_init/src/sl_device_init_emu_s1.o" "./gecko_sdk_4.4.4/platform/service/device_init/src/sl_device_init_hfxo_s1.o" "./gecko_sdk_4.4.4/platform/service/device_init/src/sl_device_init_lfxo_s1.o" "./gecko_sdk_4.4.4/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.4.4/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.4.4/platform/service/system/src/sl_system_kernel.o" "./gecko_sdk_4.4.4/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.4.4/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./gecko_sdk_4.4.4/protocol/usb/src/sl_usbd_class_cdc.o" "./gecko_sdk_4.4.4/protocol/usb/src/sl_usbd_class_cdc_acm.o" "./gecko_sdk_4.4.4/protocol/usb/src/sl_usbd_core.o" "./gecko_sdk_4.4.4/protocol/usb/src/sl_usbd_core_ep.o" "./gecko_sdk_4.4.4/protocol/usb/src/sl_usbd_core_os.o" "./gecko_sdk_4.4.4/protocol/usb/src/sl_usbd_driver_dwc_otg_fs.o" "./gecko_sdk_4.4.4/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o" "./gecko_sdk_4.4.4/util/third_party/freertos/cmsis/Source/cmsis_os2.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/croutine.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/event_groups.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/list.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/queue.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/stream_buffer.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/tasks.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/timers.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/portable/GCC/ARM_CM4F/port.o" "./gecko_sdk_4.4.4/util/third_party/freertos/kernel/portable/MemMang/heap_4.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: usb_device_cdc_acm_freertos_4.out'
	arm-none-eabi-objcopy "usb_device_cdc_acm_freertos_4.axf" "usb_device_cdc_acm_freertos_4.out"
	@echo ' '

	@echo 'Building hex file: usb_device_cdc_acm_freertos_4.hex'
	arm-none-eabi-objcopy -O ihex "usb_device_cdc_acm_freertos_4.axf" "usb_device_cdc_acm_freertos_4.hex"
	@echo ' '

	@echo 'Building bin file: usb_device_cdc_acm_freertos_4.bin'
	arm-none-eabi-objcopy -O binary "usb_device_cdc_acm_freertos_4.axf" "usb_device_cdc_acm_freertos_4.bin"
	@echo ' '

	@echo 'Building s37 file: usb_device_cdc_acm_freertos_4.s37'
	arm-none-eabi-objcopy -O srec "usb_device_cdc_acm_freertos_4.axf" "usb_device_cdc_acm_freertos_4.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "usb_device_cdc_acm_freertos_4.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) usb_device_cdc_acm_freertos_4.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
