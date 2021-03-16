###############################################################################
# MODIFICATION: HALIDE_SRC_PATH must match local filesystem!
#------------------------------------------------------------------------------
# Project Paths
###############################################################################
HALIDE_SRC_PATH                 = /home/charles/Documents/aha/Halide-to-Hardware
COREIR_SRC_PATH                 = $(HALIDE_SRC_PATH)/../coreir
BUFFER_MAPPING_SRC_PATH         = $(HALIDE_SRC_PATH)/../BufferMapping
CLOCKWORK_SRC_PATH              = $(HALIDE_SRC_PATH)/../clockwork

###############################################################################
# MODIFICATION: According to application
#------------------------------------------------------------------------------
# App-specific definitions
###############################################################################

APP_NAME                        = stream_test
# APP_NAME                        = bin/clockwork/unoptimized_conv_3_3
TOP_LEVEL_FUNCTION				= unoptimized_conv_3_3_rdai
HOST_NAME						= conv_3_3_host
APP_BIN_PATH                    = ./bin
HL_TARGET                       = host
# hardware compiler TARGET (sw_emu, hw_emu, hw)
TARGET = hw
VPP_TARGET = --target $(TARGET)

###############################################################################
# Xilinx Tools Paths
###############################################################################
XILINX_VITIS 	  ?= /opt/Xilinx/Vitis/2020.1
XILINX_VIVADO 	  ?= /opt/Xilinx//Vivado/2020.1
XILINX_VIVADO_HLS ?= $(XILINX_VITIS)/Vivado_HLS

###############################################################################
# Compiler settings
###############################################################################
HOST_CXX ?= aarch64-linux-gnu-g++
VPP 	 ?= ${XILINX_VITIS}/bin/v++
RM = rm -f
RMDIR = rm -rf

###############################################################################
# MODIFICATION: OPTIONAL, user's desired platform
#------------------------------------------------------------------------------
# Platform Variables
###############################################################################
VITIS_PLATFORM	    = ultra96v2-platform
VITIS_PLATFORM_DIR  = /home/charles/Documents/aha/FPGA_gen_v2/ultra96v2-vitis-pkg/pfm/ultra96v2-platform/export/ultra96v2-platform
VITIS_PLATFORM_PATH = $(VITIS_PLATFORM_DIR)/ultra96v2-platform.xpfm
VPP_PLATFORM		= --platform $(VITIS_PLATFORM_PATH)

###############################################################################
# Petalinux settings
###############################################################################
BOOT_SCR = /home/charles/Documents/aha/FPGA_gen_v2/ultra96v2-vitis-pkg/ultra96v2-petalinux/images/linux/boot.scr

###############################################################################
# Host Compiler FLAGS
###############################################################################
CXXFLAGS += -std=c++0x -DVITIS_PLATFORM=$(VITIS_PLATFORM) -D__USE_XOPEN2K8 -I/opt/Xilinx/Vivado/2020.1/include/ \
			-I$(VITIS_PLATFORM_DIR)/sw/$(VITIS_PLATFORM)/linux_domain/sysroot/aarch64-xilinx-linux/usr/include/xrt/ \
			-O2 -g -Wall -c -fmessage-length=0 \
			--sysroot=$(VITIS_PLATFORM_DIR)/sw/$(VITIS_PLATFORM)/linux_domain/sysroot/aarch64-xilinx-linux
LDFLAGS += -lxilinxopencl -lpthread -lrt -ldl -lcrypt -lstdc++ \
		   -L$(VITIS_PLATFORM_DIR)/sw/$(VITIS_PLATFORM)/linux_domain/sysroot/aarch64-xilinx-linux/usr/lib/ \
		   --sysroot=$(VITIS_PLATFORM_DIR)/sw/$(VITIS_PLATFORM)/linux_domain/sysroot/aarch64-xilinx-linux

###############################################################################
# OpenCL kernel files
###############################################################################
XCLBIN += $(APP_BIN_PATH)/fpga/$(APP_NAME).xclbin
XO += $(APP_BIN_PATH)/fpga/$(APP_NAME).xo # intermediate xilinx object file
HOST_OBJECT += $(APP_BIN_PATH)/fpga/src/$(HOST_NAME).o
HOST_EXE += $(APP_BIN_PATH)/fpga/$(HOST_NAME)
