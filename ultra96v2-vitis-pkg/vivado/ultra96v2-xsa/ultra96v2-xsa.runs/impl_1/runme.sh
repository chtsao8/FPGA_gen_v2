#!/bin/sh

# 
# Vivado(TM)
# runme.sh: a Vivado-generated Runs Script for UNIX
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
# 

if [ -z "$PATH" ]; then
  PATH=/cad/xilinx/vivado/2020.1/Vivado/2020.1/ids_lite/ISE/bin/lin64:/cad/xilinx/vivado/2020.1/Vivado/2020.1/bin
else
  PATH=/cad/xilinx/vivado/2020.1/Vivado/2020.1/ids_lite/ISE/bin/lin64:/cad/xilinx/vivado/2020.1/Vivado/2020.1/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD='/home/chtsao/aha/FPGA_gen_v2/ultra96v2-vitis-pkg/vivado/ultra96v2-xsa/ultra96v2-xsa.runs/impl_1'
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

# pre-commands:
/bin/touch .init_design.begin.rst
EAStep vivado -log ultra96v2_design_wrapper.vdi -applog -m64 -product Vivado -messageDb vivado.pb -mode batch -source ultra96v2_design_wrapper.tcl -notrace

