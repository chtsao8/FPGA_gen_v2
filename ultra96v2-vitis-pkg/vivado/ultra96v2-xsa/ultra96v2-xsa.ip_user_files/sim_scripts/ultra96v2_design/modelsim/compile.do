vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xilinx_vip
vlib modelsim_lib/msim/xpm
vlib modelsim_lib/msim/axi_infrastructure_v1_1_0
vlib modelsim_lib/msim/axi_vip_v1_1_7
vlib modelsim_lib/msim/zynq_ultra_ps_e_vip_v1_0_7
vlib modelsim_lib/msim/xil_defaultlib
vlib modelsim_lib/msim/lib_cdc_v1_0_2
vlib modelsim_lib/msim/proc_sys_reset_v5_0_13
vlib modelsim_lib/msim/axi_lite_ipif_v3_0_4
vlib modelsim_lib/msim/axi_intc_v4_1_14
vlib modelsim_lib/msim/generic_baseblocks_v2_1_0
vlib modelsim_lib/msim/fifo_generator_v13_2_5
vlib modelsim_lib/msim/axi_data_fifo_v2_1_20
vlib modelsim_lib/msim/axi_register_slice_v2_1_21
vlib modelsim_lib/msim/axi_protocol_converter_v2_1_21

vmap xilinx_vip modelsim_lib/msim/xilinx_vip
vmap xpm modelsim_lib/msim/xpm
vmap axi_infrastructure_v1_1_0 modelsim_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_7 modelsim_lib/msim/axi_vip_v1_1_7
vmap zynq_ultra_ps_e_vip_v1_0_7 modelsim_lib/msim/zynq_ultra_ps_e_vip_v1_0_7
vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib
vmap lib_cdc_v1_0_2 modelsim_lib/msim/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 modelsim_lib/msim/proc_sys_reset_v5_0_13
vmap axi_lite_ipif_v3_0_4 modelsim_lib/msim/axi_lite_ipif_v3_0_4
vmap axi_intc_v4_1_14 modelsim_lib/msim/axi_intc_v4_1_14
vmap generic_baseblocks_v2_1_0 modelsim_lib/msim/generic_baseblocks_v2_1_0
vmap fifo_generator_v13_2_5 modelsim_lib/msim/fifo_generator_v13_2_5
vmap axi_data_fifo_v2_1_20 modelsim_lib/msim/axi_data_fifo_v2_1_20
vmap axi_register_slice_v2_1_21 modelsim_lib/msim/axi_register_slice_v2_1_21
vmap axi_protocol_converter_v2_1_21 modelsim_lib/msim/axi_protocol_converter_v2_1_21

vlog -work xilinx_vip -64 -incr -sv -L axi_vip_v1_1_7 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm -64 -incr -sv -L axi_vip_v1_1_7 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -64 -93 \
"/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0 -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_7 -64 -incr -sv -L axi_vip_v1_1_7 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ce6c/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work zynq_ultra_ps_e_vip_v1_0_7 -64 -incr -sv -L axi_vip_v1_1_7 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_zynq_ultra_ps_e_0_0/sim/ultra96v2_design_zynq_ultra_ps_e_0_0_vip_wrapper.v" \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_clk_wiz_0_0/ultra96v2_design_clk_wiz_0_0_clk_wiz.v" \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_clk_wiz_0_0/ultra96v2_design_clk_wiz_0_0.v" \

vcom -work lib_cdc_v1_0_2 -64 -93 \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13 -64 -93 \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_0_0/sim/ultra96v2_design_proc_sys_reset_0_0.vhd" \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_1_0/sim/ultra96v2_design_proc_sys_reset_1_0.vhd" \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_2_0/sim/ultra96v2_design_proc_sys_reset_2_0.vhd" \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_proc_sys_reset_3_0/sim/ultra96v2_design_proc_sys_reset_3_0.vhd" \

vcom -work axi_lite_ipif_v3_0_4 -64 -93 \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/66ea/hdl/axi_lite_ipif_v3_0_vh_rfs.vhd" \

vcom -work axi_intc_v4_1_14 -64 -93 \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/f78a/hdl/axi_intc_v4_1_vh_rfs.vhd" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_axi_intc_0_0/sim/ultra96v2_design_axi_intc_0_0.vhd" \

vlog -work generic_baseblocks_v2_1_0 -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_5 -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/276e/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_5 -64 -93 \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/276e/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_5 -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/276e/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_20 -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/47c9/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_21 -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/2ef9/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work axi_protocol_converter_v2_1_21 -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8dfa/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/ec67/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/e257/hdl" "+incdir+../../../../ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ipshared/8b3d" "+incdir+/cad/xilinx/vivado/2020.1/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/ultra96v2_design/ip/ultra96v2_design_auto_pc_0/sim/ultra96v2_design_auto_pc_0.v" \
"../../../bd/ultra96v2_design/sim/ultra96v2_design.v" \

vlog -work xil_defaultlib \
"glbl.v"

