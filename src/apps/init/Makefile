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

# Source files required to build the target
CFILES   := $(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/src/*.c))

ifneq (${CONFIG_HAVE_CRT},y)
ASMFILES := $(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/crt/arch-${ARCH}/crt0.S))
endif

NK_CFLAGS += -std=gnu99 -O2

# Libraries required to build the target
LIBS := sel4 muslc playground

include $(SEL4_COMMON)/common.mk
