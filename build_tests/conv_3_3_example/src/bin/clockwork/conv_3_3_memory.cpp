#include "app.h"
#include "ubuffer.h"
#include "codegen.h"
#include "prog.h"

prog conv_3_3() {
  prog prg;
  prg.compute_unit_file = "conv_3_3_compute.h";
  prg.name = "conv_3_3";

// Stencil<uint16_t, 64, 64> &hw_input_stencil = arg_0;
  prg.add_input("hw_input_stencil");
  prg.buffer_port_widths["hw_input_stencil"] = 16;
// Stencil<uint16_t, 62, 62> &hw_output_stencil = arg_1;
  prg.add_output("hw_output_stencil");
  prg.buffer_port_widths["hw_output_stencil"] = 16;

////producing hw_input_global_wrapper.stencil
  auto hw_input_global_wrapper_s0_y = prg.add_loop("hw_input_global_wrapper_s0_y", 0, 64);
  auto hw_input_global_wrapper_s0_x = hw_input_global_wrapper_s0_y->add_loop("hw_input_global_wrapper_s0_x", 0, 64);

//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
  auto hcompute_hw_input_global_wrapper_stencil = hw_input_global_wrapper_s0_x->add_op("op_hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_function("hcompute_hw_input_global_wrapper_stencil");
  hcompute_hw_input_global_wrapper_stencil->add_load("hw_input_stencil", "hw_input_global_wrapper_s0_y", "hw_input_global_wrapper_s0_x");
  prg.buffer_port_widths["hw_input_global_wrapper_stencil"] = 16;
  hcompute_hw_input_global_wrapper_stencil->add_store("hw_input_global_wrapper_stencil", "hw_input_global_wrapper_s0_y", "hw_input_global_wrapper_s0_x");

//consuming hw_input_global_wrapper.stencil
  auto hw_output_s0_y_v33 = prg.add_loop("hw_output_s0_y_v33", 0, 62);
  auto hw_output_s0_x_v32 = hw_output_s0_y_v33->add_loop("hw_output_s0_x_v32", 0, 62);
////producing conv.stencil

//store is: conv.stencil(hw_output_s0_x_v32, hw_output_s0_y_v33) = (uint16)0
  auto hcompute_conv_stencil = hw_output_s0_x_v32->add_op("op_hcompute_conv_stencil");
  hcompute_conv_stencil->add_function("hcompute_conv_stencil");
  prg.buffer_port_widths["conv_stencil"] = 16;
  hcompute_conv_stencil->add_store("conv_stencil", "hw_output_s0_y_v33", "hw_output_s0_x_v32");

//store is: conv.stencil(hw_output_s0_x_v32, hw_output_s0_y_v33) = ((hw_input_global_wrapper.stencil(hw_output_s0_x_v32, hw_output_s0_y_v33)*(uint16)17) + (conv.stencil(hw_output_s0_x_v32, hw_output_s0_y_v33) + ((hw_input_global_wrapper.stencil((hw_output_s0_x_v32 + 1), hw_output_s0_y_v33)*(uint16)4) + ((hw_input_global_wrapper.stencil((hw_output_s0_x_v32 + 2), hw_output_s0_y_v33)*(uint16)6) + ((hw_input_global_wrapper.stencil(hw_output_s0_x_v32, (hw_output_s0_y_v33 + 1))*(uint16)7) + ((hw_input_global_wrapper.stencil((hw_output_s0_x_v32 + 1), (hw_output_s0_y_v33 + 1))*(uint16)19) + ((hw_input_global_wrapper.stencil((hw_output_s0_x_v32 + 2), (hw_output_s0_y_v33 + 1))*(uint16)4) + ((hw_input_global_wrapper.stencil(hw_output_s0_x_v32, (hw_output_s0_y_v33 + 2))*(uint16)5) + ((hw_input_global_wrapper.stencil((hw_output_s0_x_v32 + 2), (hw_output_s0_y_v33 + 2))*(uint16)15) + (hw_input_global_wrapper.stencil((hw_output_s0_x_v32 + 1), (hw_output_s0_y_v33 + 2))*(uint16)21))))))))))
  auto hcompute_conv_stencil_1 = hw_output_s0_x_v32->add_op("op_hcompute_conv_stencil_1");
  hcompute_conv_stencil_1->add_function("hcompute_conv_stencil_1");
  hcompute_conv_stencil_1->add_load("conv_stencil", "hw_output_s0_y_v33", "hw_output_s0_x_v32");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "hw_output_s0_y_v33", "hw_output_s0_x_v32");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "hw_output_s0_y_v33", "(hw_output_s0_x_v32 + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "hw_output_s0_y_v33", "(hw_output_s0_x_v32 + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(hw_output_s0_y_v33 + 1)", "hw_output_s0_x_v32");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(hw_output_s0_y_v33 + 1)", "(hw_output_s0_x_v32 + 1)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(hw_output_s0_y_v33 + 1)", "(hw_output_s0_x_v32 + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(hw_output_s0_y_v33 + 2)", "hw_output_s0_x_v32");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(hw_output_s0_y_v33 + 2)", "(hw_output_s0_x_v32 + 2)");
  hcompute_conv_stencil_1->add_load("hw_input_global_wrapper_stencil", "(hw_output_s0_y_v33 + 2)", "(hw_output_s0_x_v32 + 1)");
  hcompute_conv_stencil_1->add_store("conv_stencil", "hw_output_s0_y_v33", "hw_output_s0_x_v32");

//consuming conv.stencil

//store is: hw_output.stencil(hw_output_s0_x_v32, hw_output_s0_y_v33) = conv.stencil(hw_output_s0_x_v32, hw_output_s0_y_v33)
  auto hcompute_hw_output_stencil = hw_output_s0_x_v32->add_op("op_hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_function("hcompute_hw_output_stencil");
  hcompute_hw_output_stencil->add_load("conv_stencil", "hw_output_s0_y_v33", "hw_output_s0_x_v32");
  hcompute_hw_output_stencil->add_store("hw_output_stencil", "hw_output_s0_y_v33", "hw_output_s0_x_v32");

// TLAST Generation
  prg.add_output("tlast");
  prg.buffer_port_widths["tlast"] = 1;
  auto hcompute_tlast_op = hw_output_s0_x_v32->add_op("op_hcompute_tlast");
  hcompute_tlast_op->add_function("hcompute_tlast");
  hcompute_tlast_op->add_store("tlast", "hw_output_s0_x_v32", "hw_output_s0_y_v33");
  hcompute_tlast_op->compute_unit_needs_index_variable("hw_output_s0_x_v32");
  hcompute_tlast_op->compute_unit_needs_index_variable("hw_output_s0_y_v33");

  return prg;
}
