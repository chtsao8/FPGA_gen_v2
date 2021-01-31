-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2020.1 (lin64) Build 2902540 Wed May 27 19:54:35 MDT 2020
-- Date        : Sat Jan 30 00:54:10 2021
-- Host        : kiwi running 64-bit Ubuntu 18.04.5 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/chtsao/aha/FPGA_gen_v2/ultra96v2-vitis-pkg/vivado/ultra96v2-xsa/ultra96v2-xsa.srcs/sources_1/bd/ultra96v2_design/ip/ultra96v2_design_clk_wiz_0_0/ultra96v2_design_clk_wiz_0_0_stub.vhdl
-- Design      : ultra96v2_design_clk_wiz_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xczu3eg-sbva484-1-e
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ultra96v2_design_clk_wiz_0_0 is
  Port ( 
    clk_out1 : out STD_LOGIC;
    clk_out2 : out STD_LOGIC;
    clk_out3 : out STD_LOGIC;
    clk_out4 : out STD_LOGIC;
    resetn : in STD_LOGIC;
    locked : out STD_LOGIC;
    clk_in1 : in STD_LOGIC
  );

end ultra96v2_design_clk_wiz_0_0;

architecture stub of ultra96v2_design_clk_wiz_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk_out1,clk_out2,clk_out3,clk_out4,resetn,locked,clk_in1";
begin
end;
