#include "ap_int.h"
#include "hls_stream.h"

template <int WIDTH>
struct Data_t {
    ap_uint<WIDTH> data;
    ap_uint<1> tlast;
};

void unoptimized_conv_3_3_rdai(hls::stream<Data_t<32> > &arg_in0,
                               hls::stream<Data_t<32> > &arg_out) {
#pragma HLS DATAFLOW
#pragma HLS INTERFACE axis register port = arg_in0 name = arg_in0_v
#pragma HLS INTERFACE axis register port = arg_out name = arg_out_v
#pragma HLS INTERFACE ap_ctrl_none port = return

    while (1) {
        Data_t<32> temp = arg_in0.read();
        arg_out.write(temp);
    }
}
