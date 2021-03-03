#ifndef __VIVADO_SYNTH__
#include <fstream>
using namespace std;

  // Debug utility
  ofstream* global_debug_handle;

#endif //__VIVADO_SYNTH__
// compute file: conv_3_3_compute.h
#include "conv_3_3_compute.h"

#include "hw_classes.h"

struct conv_stencil_all_inputs_to_all_outputs_cache {
	// RAM Box: {[0, 61], [0, 61]}
  hw_uint<16> RAM[62][62];
  inline hw_uint<16> read(int d0, int d1) {
    return RAM[d0][d1];
  }



	inline void write(const hw_uint<16> value, int d0, int d1) {
    RAM[d0][d1] = value;
  }

};

struct conv_stencil_cache {
  // # of banks: 1
  conv_stencil_all_inputs_to_all_outputs_cache conv_stencil_all_inputs_to_all_outputs;
};



inline void conv_stencil_op_hcompute_conv_stencil_1_3_write(hw_uint<16>& conv_stencil_op_hcompute_conv_stencil_1_3, conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
  conv_stencil.conv_stencil_all_inputs_to_all_outputs.write(conv_stencil_op_hcompute_conv_stencil_1_3, hw_output_s0_y_v33 - 0, hw_output_s0_x_v32 - 0);
}

inline void conv_stencil_op_hcompute_conv_stencil_2_write(hw_uint<16>& conv_stencil_op_hcompute_conv_stencil_2, conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
  conv_stencil.conv_stencil_all_inputs_to_all_outputs.write(conv_stencil_op_hcompute_conv_stencil_2, hw_output_s0_y_v33 - 0, hw_output_s0_x_v32 - 0);
}

inline hw_uint<16> conv_stencil_op_hcompute_conv_stencil_1_4_select(conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // conv_stencil_op_hcompute_conv_stencil_1_4 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> conv_stencil[hw_output_s0_y_v33, hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_conv_stencil_op_hcompute_conv_stencil_1_3 = conv_stencil.conv_stencil_all_inputs_to_all_outputs.read(hw_output_s0_y_v33 - 0, hw_output_s0_x_v32 - 0);
  return value_conv_stencil_op_hcompute_conv_stencil_1_3;
  return 0;
}

inline hw_uint<16> conv_stencil_op_hcompute_hw_output_stencil_15_select(conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // conv_stencil_op_hcompute_hw_output_stencil_15 read pattern: { op_hcompute_hw_output_stencil[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> conv_stencil[hw_output_s0_y_v33, hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_conv_stencil_op_hcompute_conv_stencil_1_3 = conv_stencil.conv_stencil_all_inputs_to_all_outputs.read(hw_output_s0_y_v33 - 0, hw_output_s0_x_v32 - 0);
  return value_conv_stencil_op_hcompute_conv_stencil_1_3;
  return 0;
}

// # of bundles = 4
// op_hcompute_conv_stencil_1_read
//	conv_stencil_op_hcompute_conv_stencil_1_4
inline hw_uint<16> conv_stencil_op_hcompute_conv_stencil_1_read_bundle_read(conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
  // # of ports in bundle: 1
    // conv_stencil_op_hcompute_conv_stencil_1_4

	hw_uint<16> result;
	hw_uint<16> conv_stencil_op_hcompute_conv_stencil_1_4_res = conv_stencil_op_hcompute_conv_stencil_1_4_select(conv_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<0, 16>(result, conv_stencil_op_hcompute_conv_stencil_1_4_res);
	return result;
}

// op_hcompute_conv_stencil_1_write
//	conv_stencil_op_hcompute_conv_stencil_1_3
inline void conv_stencil_op_hcompute_conv_stencil_1_write_bundle_write(hw_uint<16>& op_hcompute_conv_stencil_1_write, conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
	hw_uint<16> conv_stencil_op_hcompute_conv_stencil_1_3_res = op_hcompute_conv_stencil_1_write.extract<0, 15>();
	conv_stencil_op_hcompute_conv_stencil_1_3_write(conv_stencil_op_hcompute_conv_stencil_1_3_res, conv_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
}

// op_hcompute_conv_stencil_write
//	conv_stencil_op_hcompute_conv_stencil_2
inline void conv_stencil_op_hcompute_conv_stencil_write_bundle_write(hw_uint<16>& op_hcompute_conv_stencil_write, conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
	hw_uint<16> conv_stencil_op_hcompute_conv_stencil_2_res = op_hcompute_conv_stencil_write.extract<0, 15>();
	conv_stencil_op_hcompute_conv_stencil_2_write(conv_stencil_op_hcompute_conv_stencil_2_res, conv_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
}

// op_hcompute_hw_output_stencil_read
//	conv_stencil_op_hcompute_hw_output_stencil_15
inline hw_uint<16> conv_stencil_op_hcompute_hw_output_stencil_read_bundle_read(conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
  // # of ports in bundle: 1
    // conv_stencil_op_hcompute_hw_output_stencil_15

	hw_uint<16> result;
	hw_uint<16> conv_stencil_op_hcompute_hw_output_stencil_15_res = conv_stencil_op_hcompute_hw_output_stencil_15_select(conv_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<0, 16>(result, conv_stencil_op_hcompute_hw_output_stencil_15_res);
	return result;
}

#include "hw_classes.h"

struct hw_input_global_wrapper_stencil_all_inputs_to_all_outputs_cache {
	// RAM Box: {[0, 63], [0, 63]}
  hw_uint<16> RAM[64][64];
  inline hw_uint<16> read(int d0, int d1) {
    return RAM[d0][d1];
  }



	inline void write(const hw_uint<16> value, int d0, int d1) {
    RAM[d0][d1] = value;
  }

};

struct hw_input_global_wrapper_stencil_cache {
  // # of banks: 1
  hw_input_global_wrapper_stencil_all_inputs_to_all_outputs_cache hw_input_global_wrapper_stencil_all_inputs_to_all_outputs;
};



inline void hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0_write(hw_uint<16>& hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0, hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_input_global_wrapper_s0_y, int hw_input_global_wrapper_s0_x, int dynamic_address) {
  hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.write(hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0, hw_input_global_wrapper_s0_y - 0, hw_input_global_wrapper_s0_x - 0);
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_10_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_10 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[1 + hw_output_s0_y_v33, 2 + hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(1 + hw_output_s0_y_v33 - 0, 2 + hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_11_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_11 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[2 + hw_output_s0_y_v33, hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(2 + hw_output_s0_y_v33 - 0, hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_12_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_12 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[2 + hw_output_s0_y_v33, 2 + hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(2 + hw_output_s0_y_v33 - 0, 2 + hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_13_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_13 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[2 + hw_output_s0_y_v33, 1 + hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(2 + hw_output_s0_y_v33 - 0, 1 + hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_5_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_5 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[hw_output_s0_y_v33, hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(hw_output_s0_y_v33 - 0, hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_6_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_6 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[hw_output_s0_y_v33, 1 + hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(hw_output_s0_y_v33 - 0, 1 + hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_7_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_7 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[hw_output_s0_y_v33, 2 + hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(hw_output_s0_y_v33 - 0, 2 + hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_8_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_8 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[1 + hw_output_s0_y_v33, hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(1 + hw_output_s0_y_v33 - 0, hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

inline hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_9_select(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_9 read pattern: { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_input_global_wrapper_stencil[1 + hw_output_s0_y_v33, 1 + hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
  auto value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0 = hw_input_global_wrapper_stencil.hw_input_global_wrapper_stencil_all_inputs_to_all_outputs.read(1 + hw_output_s0_y_v33 - 0, 1 + hw_output_s0_x_v32 - 0);
  return value_hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0;
  return 0;
}

// # of bundles = 2
// op_hcompute_conv_stencil_1_read
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_5
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_6
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_7
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_8
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_9
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_10
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_11
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_12
//	hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_13
inline hw_uint<144> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_read_bundle_read(hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32, int dynamic_address) {
  // # of ports in bundle: 9
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_5
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_6
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_7
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_8
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_9
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_10
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_11
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_12
    // hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_13

	hw_uint<144> result;
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_5_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_5_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<0, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_5_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_6_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_6_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<16, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_6_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_7_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_7_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<32, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_7_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_8_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_8_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<48, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_8_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_9_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_9_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<64, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_9_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_10_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_10_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<80, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_10_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_11_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_11_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<96, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_11_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_12_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_12_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<112, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_12_res);
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_13_res = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_13_select(hw_input_global_wrapper_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, dynamic_address);
	set_at<128, 144>(result, hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_13_res);
	return result;
}

// op_hcompute_hw_input_global_wrapper_stencil_write
//	hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0
inline void hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_write_bundle_write(hw_uint<16>& op_hcompute_hw_input_global_wrapper_stencil_write, hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_input_global_wrapper_s0_y, int hw_input_global_wrapper_s0_x, int dynamic_address) {
	hw_uint<16> hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0_res = op_hcompute_hw_input_global_wrapper_stencil_write.extract<0, 15>();
	hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0_write(hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_0_res, hw_input_global_wrapper_stencil, root, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, dynamic_address);
}

// Total re-use buffer capacity: 127040 bits


// Operation logic
inline void op_hcompute_hw_input_global_wrapper_stencil(HWStream<hw_uint<16> >& /* buffer_args num ports = 1 */hw_input_stencil, hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_input_global_wrapper_s0_y, int hw_input_global_wrapper_s0_x) {
  // Dynamic address computation

	// Consume: hw_input_stencil
	auto hw_input_stencil_hw_input_global_wrapper_s0_y_c__hw_input_global_wrapper_s0_x_value = hw_input_stencil.read();
	auto compute_result = hcompute_hw_input_global_wrapper_stencil(hw_input_stencil_hw_input_global_wrapper_s0_y_c__hw_input_global_wrapper_s0_x_value);
	// Produce: hw_input_global_wrapper_stencil
	hw_input_global_wrapper_stencil_op_hcompute_hw_input_global_wrapper_stencil_write_bundle_write(/* arg names */compute_result, hw_input_global_wrapper_stencil, root, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x, 0);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

}

inline void op_hcompute_conv_stencil(conv_stencil_cache& conv_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32) {
  // Dynamic address computation

	auto compute_result = hcompute_conv_stencil();
	// Produce: conv_stencil
	conv_stencil_op_hcompute_conv_stencil_write_bundle_write(/* arg names */compute_result, conv_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, 0);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

}

inline void op_hcompute_conv_stencil_1(conv_stencil_cache& conv_stencil, hw_input_global_wrapper_stencil_cache& hw_input_global_wrapper_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32) {
  // Dynamic address computation

	// Consume: conv_stencil
	auto conv_stencil_hw_output_s0_y_v33_c__hw_output_s0_x_v32_value = conv_stencil_op_hcompute_conv_stencil_1_read_bundle_read(conv_stencil/* source_delay */, root, hw_output_s0_y_v33, hw_output_s0_x_v32, 0);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

	// Consume: hw_input_global_wrapper_stencil
	auto hw_input_global_wrapper_stencil_hw_output_s0_y_v33_c__hw_output_s0_x_v32_value = hw_input_global_wrapper_stencil_op_hcompute_conv_stencil_1_read_bundle_read(hw_input_global_wrapper_stencil/* source_delay */, root, hw_output_s0_y_v33, hw_output_s0_x_v32, 0);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

	auto compute_result = hcompute_conv_stencil_1(conv_stencil_hw_output_s0_y_v33_c__hw_output_s0_x_v32_value, hw_input_global_wrapper_stencil_hw_output_s0_y_v33_c__hw_output_s0_x_v32_value);
	// Produce: conv_stencil
	conv_stencil_op_hcompute_conv_stencil_1_write_bundle_write(/* arg names */compute_result, conv_stencil, root, hw_output_s0_y_v33, hw_output_s0_x_v32, 0);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

}

inline void op_hcompute_hw_output_stencil(conv_stencil_cache& conv_stencil, HWStream<hw_uint<16> >& /* buffer_args num ports = 1 */hw_output_stencil, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32) {
  // Dynamic address computation

	// Consume: conv_stencil
	auto conv_stencil_hw_output_s0_y_v33_c__hw_output_s0_x_v32_value = conv_stencil_op_hcompute_hw_output_stencil_read_bundle_read(conv_stencil/* source_delay */, root, hw_output_s0_y_v33, hw_output_s0_x_v32, 0);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

	auto compute_result = hcompute_hw_output_stencil(conv_stencil_hw_output_s0_y_v33_c__hw_output_s0_x_v32_value);
	// Produce: hw_output_stencil
	hw_output_stencil.write(compute_result);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

}

inline void op_hcompute_tlast(HWStream<hw_uint<1> >& /* buffer_args num ports = 1 */tlast, int root, int hw_output_s0_y_v33, int hw_output_s0_x_v32) {
  // Dynamic address computation

	auto compute_result = hcompute_tlast(hw_output_s0_x_v32, hw_output_s0_y_v33);
	// Produce: tlast
	tlast.write(compute_result);

#ifndef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__

}

// Driver function
void unoptimized_conv_3_3(HWStream<hw_uint<16> >& /* no bundle get_args num ports = 1 */hw_input_stencil, HWStream<hw_uint<16> >& /* no bundle get_args num ports = 1 */hw_output_stencil, HWStream<hw_uint<1> >& /* no bundle get_args num ports = 1 */tlast) {

#ifndef __VIVADO_SYNTH__
  ofstream debug_file("unoptimized_conv_3_3_debug.csv");
  global_debug_handle = &debug_file;
#endif //__VIVADO_SYNTH__
  conv_stencil_cache conv_stencil;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  hw_input_global_wrapper_stencil_cache hw_input_global_wrapper_stencil;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
#ifdef __VIVADO_SYNTH__
#pragma HLS inline recursive
#endif // __VIVADO_SYNTH__

// schedule: { op_hcompute_tlast[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 3] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61; op_hcompute_conv_stencil[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 0] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61; op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> [0, 0, 0, hw_input_global_wrapper_s0_y, 0, hw_input_global_wrapper_s0_x, 0] : 0 <= hw_input_global_wrapper_s0_y <= 63 and 0 <= hw_input_global_wrapper_s0_x <= 63; op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 1] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61; op_hcompute_hw_output_stencil[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 2] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
//   { op_hcompute_tlast[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 3] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
// Condition for op_hcompute_tlast(((-3 + i6 == 0) && (i4 == 0) && (-1 + i2 == 0) && (i1 == 0) && (i0 == 0) && (i3 >= 0) && (61 - i3 >= 0) && (i5 >= 0) && (61 - i5 >= 0)))
//   { op_hcompute_conv_stencil[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 0] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
// Condition for op_hcompute_conv_stencil(((i6 == 0) && (i4 == 0) && (-1 + i2 == 0) && (i1 == 0) && (i0 == 0) && (i3 >= 0) && (61 - i3 >= 0) && (i5 >= 0) && (61 - i5 >= 0)))
//   { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> [0, 0, 0, hw_input_global_wrapper_s0_y, 0, hw_input_global_wrapper_s0_x, 0] : 0 <= hw_input_global_wrapper_s0_y <= 63 and 0 <= hw_input_global_wrapper_s0_x <= 63 }
// Condition for op_hcompute_hw_input_global_wrapper_stencil(((i6 == 0) && (i4 == 0) && (i2 == 0) && (i1 == 0) && (i0 == 0) && (i3 >= 0) && (63 - i3 >= 0) && (i5 >= 0) && (63 - i5 >= 0)))
//   { op_hcompute_conv_stencil_1[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 1] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
// Condition for op_hcompute_conv_stencil_1(((-1 + i6 == 0) && (i4 == 0) && (-1 + i2 == 0) && (i1 == 0) && (i0 == 0) && (i3 >= 0) && (61 - i3 >= 0) && (i5 >= 0) && (61 - i5 >= 0)))
//   { op_hcompute_hw_output_stencil[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> [0, 0, 1, hw_output_s0_y_v33, 0, hw_output_s0_x_v32, 2] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
// Condition for op_hcompute_hw_output_stencil(((-2 + i6 == 0) && (i4 == 0) && (-1 + i2 == 0) && (i1 == 0) && (i0 == 0) && (i3 >= 0) && (61 - i3 >= 0) && (i5 >= 0) && (61 - i5 >= 0)))

  /*
{
  for (int c3 = 0; c3 <= 63; c3 += 1)
    for (int c5 = 0; c5 <= 63; c5 += 1)
      op_hcompute_hw_input_global_wrapper_stencil(0, c3, c5);
  for (int c3 = 0; c3 <= 61; c3 += 1)
    for (int c5 = 0; c5 <= 61; c5 += 1) {
      op_hcompute_conv_stencil(0, c3, c5);
      op_hcompute_conv_stencil_1(0, c3, c5);
      op_hcompute_hw_output_stencil(0, c3, c5);
      op_hcompute_tlast(0, c3, c5);
    }
}

  */
	{
	  for (int c3 = 0; c3 <= 63; c3 += 1)
	    for (int c5 = 0; c5 <= 63; c5 += 1)
	      op_hcompute_hw_input_global_wrapper_stencil(hw_input_stencil /* buf name */, hw_input_global_wrapper_stencil, 0, c3, c5);
	  for (int c3 = 0; c3 <= 61; c3 += 1)
	    for (int c5 = 0; c5 <= 61; c5 += 1) {
	      op_hcompute_conv_stencil(conv_stencil, 0, c3, c5);
	      op_hcompute_conv_stencil_1(conv_stencil /* buf name */, hw_input_global_wrapper_stencil /* buf name */, 0, c3, c5);
	      op_hcompute_hw_output_stencil(conv_stencil /* buf name */, hw_output_stencil, 0, c3, c5);
	      op_hcompute_tlast(tlast, 0, c3, c5);
	    }
	}
	
#ifndef __VIVADO_SYNTH__
  debug_file.close();
#endif //__VIVADO_SYNTH__
}

void unoptimized_conv_3_3_wrapper(HWStream<hw_uint<16> >& /* no bundle get_args num ports = 1 */hw_input_stencil, HWStream<hw_uint<16> >& /* no bundle get_args num ports = 1 */hw_output_stencil, HWStream<hw_uint<1> >& /* no bundle get_args num ports = 1 */tlast, const int num_epochs) {

  for (int epoch = 0; epoch < num_epochs; epoch++) {
    unoptimized_conv_3_3(hw_input_stencil, hw_output_stencil, tlast);
  }
}
#ifdef __VIVADO_SYNTH__
  // { op_hcompute_hw_input_global_wrapper_stencil[root = 0, hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] -> hw_input_stencil[hw_input_global_wrapper_s0_y, hw_input_global_wrapper_s0_x] : 0 <= hw_input_global_wrapper_s0_y <= 63 and 0 <= hw_input_global_wrapper_s0_x <= 63 }
const int op_hcompute_hw_input_global_wrapper_stencil_read_pipe0_num_transfers = 4096;
  // { op_hcompute_hw_output_stencil[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> hw_output_stencil[hw_output_s0_y_v33, hw_output_s0_x_v32] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
const int op_hcompute_hw_output_stencil_write_pipe0_num_transfers = 3844;
  // { op_hcompute_tlast[root = 0, hw_output_s0_y_v33, hw_output_s0_x_v32] -> tlast[hw_output_s0_x_v32, hw_output_s0_y_v33] : 0 <= hw_output_s0_y_v33 <= 61 and 0 <= hw_output_s0_x_v32 <= 61 }
const int op_hcompute_tlast_write_pipe0_num_transfers = 3844;


extern "C" {

void unoptimized_conv_3_3_accel(hw_uint<16>* op_hcompute_hw_input_global_wrapper_stencil_read_pipe0, hw_uint<16>* op_hcompute_hw_output_stencil_write_pipe0, hw_uint<1>* op_hcompute_tlast_write_pipe0, const int size) { 
#pragma HLS dataflow
#pragma HLS INTERFACE m_axi port = op_hcompute_hw_input_global_wrapper_stencil_read_pipe0 offset = slave depth = 65536 bundle = gmem0
#pragma HLS INTERFACE m_axi port = op_hcompute_hw_output_stencil_write_pipe0 offset = slave depth = 65536 bundle = gmem1
#pragma HLS INTERFACE m_axi port = op_hcompute_tlast_write_pipe0 offset = slave depth = 65536 bundle = gmem2

#pragma HLS INTERFACE s_axilite port = op_hcompute_hw_input_global_wrapper_stencil_read_pipe0 bundle = control
#pragma HLS INTERFACE s_axilite port = op_hcompute_hw_output_stencil_write_pipe0 bundle = control
#pragma HLS INTERFACE s_axilite port = op_hcompute_tlast_write_pipe0 bundle = control
#pragma HLS INTERFACE s_axilite port = size bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control


  // Pipeline # 0
  static HWStream<hw_uint<16> > op_hcompute_hw_input_global_wrapper_stencil_read_pipe0_channel;
  static HWStream<hw_uint<16> > op_hcompute_hw_output_stencil_write_pipe0_channel;
  static HWStream<hw_uint<1> > op_hcompute_tlast_write_pipe0_channel;

  burst_read<16>(op_hcompute_hw_input_global_wrapper_stencil_read_pipe0, op_hcompute_hw_input_global_wrapper_stencil_read_pipe0_channel, op_hcompute_hw_input_global_wrapper_stencil_read_pipe0_num_transfers*size);

  unoptimized_conv_3_3_wrapper(op_hcompute_hw_input_global_wrapper_stencil_read_pipe0_channel, op_hcompute_hw_output_stencil_write_pipe0_channel, op_hcompute_tlast_write_pipe0_channel, size);

  burst_write<16>(op_hcompute_hw_output_stencil_write_pipe0, op_hcompute_hw_output_stencil_write_pipe0_channel, op_hcompute_hw_output_stencil_write_pipe0_num_transfers*size);
  burst_write<1>(op_hcompute_tlast_write_pipe0, op_hcompute_tlast_write_pipe0_channel, op_hcompute_tlast_write_pipe0_num_transfers*size);
}

}

template <int WIDTH>
struct hls_packed_struct {
  ap_uint<WIDTH> data;
  ap_uint<1> tlast;
};

void unoptimized_conv_3_3_rdai(hls::stream<hls_packed_struct<16> > &arg_in0, hls::stream<hls_packed_struct<16> > &arg_out) {
#pragma HLS DATAFLOW
#pragma HLS INTERFACE axis register port=arg_in0 name=arg_in0
#pragma HLS INTERFACE axis register port=arg_out name=arg_out
#pragma HLS INTERFACE ap_ctrl_none port=return

  // input HW streams
  HWStream<hw_uint<16> > arg_in0_hwstream;

  // output unpacking
  hls_packed_struct<16> temp;
  HWStream<hw_uint<16> > arg_out_data;
  HWStream<hw_uint<1> > arg_out_tlast;

  // input hls::stream to HWStream
  arg_in0_hwstream.write((int) arg_in0.read().data);

  // Xcel call
  unoptimized_conv_3_3(arg_in0_hwstream, arg_out_data, arg_out_tlast);

  // output packing
  temp.data = (int) arg_out_data.read();
  temp.tlast = (int) arg_out_tlast.read();

  arg_out.write(temp);
}
#endif //__VIVADO_SYNTH__

