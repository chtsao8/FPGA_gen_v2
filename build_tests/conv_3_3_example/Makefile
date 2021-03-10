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

APP_NAME                        = bin/clockwork/unoptimized_conv_3_3
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

###############################################################################
# primary build targets
###############################################################################

.PHONY: all clean
all: $(XCLBIN)

.NOTPARALLEL: clean

clean-host:
	-$(RMDIR) $(APP_BIN_PATH)/fpga/src

clean-fpga:
	-$(RMDIR) $(APP_BIN_PATH)/fpga

clean-package: clean-host
	-${RMDIR} $(APP_BIN_PATH)/fpga/package

clean: clean-host clean-fpga clean-package
	-${RMDIR} $(APP_BIN_PATH) .Xil .ipcache
	-${RM} xcd.log xrc.log

.PHONY: incremental
incremental: all


nothing:

###############################################################################
# binary container: generate .xclbin
###############################################################################

gen_xilinx_object: $(XO)

$(XO): ./src/$(APP_NAME).cpp
	-@mkdir -p $(@D)
	$(VPP) $(VPP_TARGET) $(VPP_PLATFORM) --compile \
	--temp_dir $(APP_BIN_PATH)/fpga --report_dir $(APP_BIN_PATH)/fpga/reports --log_dir $(APP_BIN_PATH)/fpga/logs \
	-I $(<D) -I $(CLOCKWORK_SRC_PATH) -D__VIVADO_SYNTH__ \
	-k $(TOP_LEVEL_FUNCTION) -o "$@" "$<"


gen_fpga_binary: $(XCLBIN)

$(XCLBIN): $(XO)
	-@mkdir -p $(@D)
	$(VPP) $(VPP_TARGET) $(VPP_PLATFORM) --link \
	--temp_dir $(APP_BIN_PATH)/fpga --report_dir $(APP_BIN_PATH)/fpga/reports --log_dir $(APP_BIN_PATH)/fpga/logs \
	-o "$@" "$<"

###############################################################################
# host rules
###############################################################################

$(HOST_OBJECT): ./src/$(HOST_NAME).cpp
	-@mkdir -p $(@D)
	$(HOST_CXX) $(CXXFLAGS) -o "$@" "$<"

fpga_package: $(HOST_EXE)

$(HOST_EXE): $(HOST_OBJECT)
	-@mkdir -p ./$(APP_BIN_PATH)/fpga/package
	$(HOST_CXX) -o "$@" $(+) $(LDFLAGS)
	-@$(VPP) $(VPP_TARGET) $(VPP_PLATFORM) --package \
	--temp_dir $(APP_BIN_PATH)/fpga/src --report_dir $(APP_BIN_PATH)/fpga/reports --log_dir $(APP_BIN_PATH)/fpga/logs \
	--package.domain linux_domain --package.sd_file $(HOST_EXE) \
	--package.kernel_image $(VITIS_PLATFORM_DIR)/sw/$(VITIS_PLATFORM)/linux_domain/image/image.ub \
	--package.rootfs $(VITIS_PLATFORM_DIR)/sw/$(VITIS_PLATFORM)/linux_domain/rootfs/rootfs.cpio \
	--package.out_dir ./$(APP_BIN_PATH)/fpga/package $(XCLBIN)
	-@cp $(BOOT_SCR) ./$(APP_BIN_PATH)/fpga/package/sd_card

send_to_fpga: $(HOST_EXE)
	-${RM} /media/charles/boot/*
	-@cp -r ./$(APP_BIN_PATH)/fpga/package/sd_card/* /media/charles/boot/