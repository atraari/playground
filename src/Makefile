#
# Copyright 2014, NICTA
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(NICTA_BSD)
#

# Taken from RefOS, adapted to suit playgroundOS

lib-dirs:=libs

# The main target we want to generate
all: playground

-include .config
export CONFIG_ELF_LOADER_USE_SEL4C
export CONFIG_ELF_LOADER_USE_MUSLC
include tools/common/project.mk

# playgroundOS ARM build command.
ifeq (${CONFIG_ARCH_ARM},y)
playground: export TOOLPREFIX=$(CONFIG_CROSS_COMPILER_PREFIX:"%"=%)
playground: common init elfloader kernel_elf
	@echo "Generating boot image: ${IMAGE_ROOT}/playground-image"
	@${SEL4_COMMON}/elfloader/gen_boot_image.sh \
		${STAGE_BASE}/kernel.elf \
		${STAGE_BASE}/bin/init \
		${IMAGE_ROOT}/playground-image
endif

# playgroundOS IA32 build command.
ifeq (${CONFIG_ARCH_IA32},y)
playground: export PATH := $(STAGE_ROOT)/dite:$(PATH)
playground: common init kernel_elf app-images
	@echo "Generating boot image: ${IMAGE_ROOT}/playground-image.iso"
	cp -f ${IMAGE_ROOT}/kernel-ia32-pc99 img-root/boot/kernel-ia32-pc99
	cp -f ${STAGE_BASE}/bin/init ./img-root/sbin/init
	./scripts/create_iso -d ./img-root/ -o ${IMAGE_ROOT}/playground-image.iso
endif

# QEMU simulation helpers.
simulate-kzm:
	qemu-system-arm -nographic -M kzm \
		-kernel images/playground-image

simulate-ia32:
	qemu-system-i386 \
		-m 512 -nographic \
		-cdrom images/playground-image.iso -boot d

simulate-ia32-graphics:
	qemu-system-i386 \
		-m 512 -cdrom images/playground-image.iso -boot d

# Help
.PHONY: help
help:
	@echo "playgroundOS - A multi-server OS on seL4."
	@echo ""
	@echo " make help            - Show this help test."
	@echo " make menuconfig      - Select build configuration via menus."
	@echo " make silentoldconfig - Update configuration with the defaults of any"
	@echo "                        newly introduced settings."
	@echo " make                 - Build everything with the current configuration."
	@echo " make playground      - Build playgroundOS."
	@echo " make docs            - Build docs/html/ Doxygen code documentation."
	@echo ""

