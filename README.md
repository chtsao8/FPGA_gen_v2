# FPGA_gen_v2
FPGA_gen_v2 is an [OpenCL](https://www.khronos.org/registry/OpenCL/specs/3.0-unified/html/OpenCL_API.html#opencl-runtime) enabled hardware flow to synthesize and execute Halide applications on a Xilinx FPGA. 

Updated from the [RDAI](https://github.com/thenextged/rdai/blob/master/README.md) framework found at [FPGA_gen](https://github.com/chtsao8/FPGA-gen).

## Installation
First, ensure all dependencies (`Halide-to-Hardware`, `coreir`, `BufferMapping`, and `clockwork`) are installed in the same top-level directory.

Instructions for a full halide-to-hardware compiler setup on Kiwi can be found [here](https://github.com/StanfordAHA/Halide-to-Hardware/blob/clockwork/INSTALL.md). **Note that these instructions slightly differ, as the `Halide-to-Hardware` and `clockwork` repos should be on the `tlast` branch.**

When all dependencies are successfully installed follow these steps to install the FPGA flow:
  1. First, switch the `Halide-to-Hardware` and `clockwork` repos to the `tlast` branch, if you haven't done so already.
  
  At the top level directory of the `Halide-to-Hardware` repo:
    <pre><code>git fetch --all
    git checkout tlast
    make -j2 distrib</code></pre>
  At the top level directory of the `clockwork` repo:
      <pre><code>git fetch --all
      git checkout tlast
      ./rebuild_and_run.sh </code></pre>
  Ensure that `line 14: #define AP_INT_MAX_W 32768` in `clockwork/hw_classes.h` is commented out, or IP generation will take a very long time!
  
  2. Load `FPGA_gen_v2` dependencies:
<pre><code>module load base vivado/2020.1 vitis</code></pre>

If the `module load` command does not work, contact Charles Tsao at chtsao@stanford.edu.

  3. Install `FPGA_gen_v2`:
<pre><code>git clone https://github.com/chtsao8/FPGA_gen_v2.git
cd FPGA_gen_v2/fpga_builder</code></pre>
In `FPGA_gen_v2/fpga_builder/build-files/Makefile.defs.inc`, change the `HALIDE_SRC_PATH` variable to point to your installation of `Halide-to-Hardware`.
  
## Applications
Applications are located in `FPGA_gen_v2/fpga_builder/apps`. A simple `conv_3_3` application exists in this directory, which can be used to test your installation.

Instructions on how to add more applications to `fpga_builder` can be found [here](APPS.md).

## Running the FPGA Pipeline
In order to run a full Halide-to-Hardware pipeline on a Xilinx FPGA, follow these steps:
1. From the top level directory of FPGA-gen, change into the application directory: `cd fpga_builder/apps/<APP>`
2. In the app's Makefile, you can choose your Halide runtime target by setting `HL_TARGET`. This is currently set to `arm-64-linux`, but should be changed for your appropriate hardware target's processor.
3. Also within the app's Makefile, you should specify the name of the application's top level function. You should also specify the directory your Vitis platform (.xpfm) is located in. The Vitis platform should be changed accordingly for your desired Xilinx FPGA target.
4. Generate FPGA kernel design: 
<pre><code>make clockwork_unopt_hls
make gen_xilinx_object
make gen_fpga_binary</code></pre>
5. Compile FPGA host code:
<pre><code>make app_fpga
</code></pre>
6. Package FPGA files with Host executable:
<pre><code>make package_fpga
</code></pre>
8. Send generated FPGA target files to bootable SD card:
<pre><code>make send_to_fpga (may not work on kiwi)
</code></pre>
9. Plug SD card into FPGA, open the FPGA's command line using a program like PuTTY. Run pipeline with implemented hardware kernels: 
<pre><code> ./{host executable} {APP.xclbin}
</code></pre>
10. Compare output to cpu output: **(NOT YET IMPLEMENTED)**

Here is a list of the different make targets:
<pre><code>make clean               # remove generated files (bin directory)
     clean-clockwork     # remove clockwork-specific generated files (bin)
     clean-cpu           # remove cpu-specific generated files (bin)
     bin                 # create bin folder
     app_cpu             # build CPU app
     app_fpga            # build FPGA host code
     clockwork_unopt_hls # create clockwork HLS design
     gen_xilinx_object   # generates Vitis Xilinx Object (.xo)
     gen_fpga_binary     # generates completed FPGA binary, kernel+platform (.xclbin)
     package_fpga        # packages FPGA host executable with fpga binary to be sent to FPGA
     send_to_fpga        # copies host executable and fpga binary along with boot files to sd card
     </code></pre>

The definition of all of Makefile targets can be found in `fpga_builder/Makefile.targets.inc`.

*NOTE: Older instructions on running applications in the `Halide-to-Hardware` repo can be found [here](https://github.com/StanfordAHA/Halide-to-Hardware/blob/tlast/USAGE.md)*.
