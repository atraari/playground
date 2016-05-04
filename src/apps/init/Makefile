#
# Copyright 2014, NICTA
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(NICTA_BSD)
#

# Targets
TARGETS := $(notdir $(SOURCE_DIR)).bin

# Set custom entry point as we are a rootserver and will not be
# started in a standard way
ENTRY_POINT := _sel4_start

# Source files required to build the target
CFILES   := $(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/src/*.c))

# CPIO archive
OFILES := archive.o

# Libraries required to build the target
LIBS := sel4 c cpio playgroundsys playground utils sel4utils sel4allocman sel4simple elf sel4platsupport platsupport sel4vspace sel4vka sel4vspace
LIBS += sel4simple-default

# extra cflag for sel4test
CFLAGS += -Werror -g
ifdef CONFIG_X86_64
CFLAGS += -mno-sse
endif

include $(SEL4_COMMON)/common.mk

# targets to generate CPIO archive of elf files
${COMPONENTS}:
	false

archive.o: ${COMPONENTS}
	$(Q)mkdir -p $(dir $@)
	${COMMON_PATH}/files_to_obj.sh $@ _cpio_archive $^


