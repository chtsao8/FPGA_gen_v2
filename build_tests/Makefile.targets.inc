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

host: $(HOST_OBJECT)

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