-makelib xcelium_lib/xilinx_vip -sv \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/rst_vip_if.sv" \
-endlib
-makelib xcelium_lib/xpm -sv \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/axi_infrastructure_v1_1_0 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_vip_v1_1_7 -sv \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ce6c/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/zynq_ultra_ps_e_vip_v1_0_7 -sv \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_zynq_ultra_ps_e_0_0/sim/ultra96v2_design_zynq_ultra_ps_e_0_0_vip_wrapper.v" \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_clk_wiz_0_0/ultra96v2_design_clk_wiz_0_0_clk_wiz.v" \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_clk_wiz_0_0/ultra96v2_design_clk_wiz_0_0.v" \
-endlib
-makelib xcelium_lib/lib_cdc_v1_0_2 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/proc_sys_reset_v5_0_13 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_0_0/sim/ultra96v2_design_proc_sys_reset_0_0.vhd" \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_1_0/sim/ultra96v2_design_proc_sys_reset_1_0.vhd" \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_2_0/sim/ultra96v2_design_proc_sys_reset_2_0.vhd" \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_3_0/sim/ultra96v2_design_proc_sys_reset_3_0.vhd" \
-endlib
-makelib xcelium_lib/axi_lite_ipif_v3_0_4 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/66ea/hdl/axi_lite_ipif_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_intc_v4_1_14 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/f78a/hdl/axi_intc_v4_1_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_axi_intc_0_0/sim/ultra96v2_design_axi_intc_0_0.vhd" \
-endlib
-makelib xcelium_lib/generic_baseblocks_v2_1_0 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_5 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/276e/simulation/fifo_generator_vlog_beh.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_5 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/276e/hdl/fifo_generator_v13_2_rfs.vhd" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_5 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/276e/hdl/fifo_generator_v13_2_rfs.v" \
-endlib
-makelib xcelium_lib/axi_data_fifo_v2_1_20 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/47c9/hdl/axi_data_fifo_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_register_slice_v2_1_21 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/2ef9/hdl/axi_register_slice_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_protocol_converter_v2_1_21 \
  "../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8dfa/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/ultra96v2_design/ip/ultra96v2_design_auto_pc_0/sim/ultra96v2_design_auto_pc_0.v" \
  "../../../bd/ultra96v2_design/sim/ultra96v2_design.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

