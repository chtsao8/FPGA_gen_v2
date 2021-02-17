#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "vadd.h"

static const int DATA_SIZE = 4096;

static const std::string error_message =
    "Error: Result mismatch:\n"
    "i = %d CPU result = %d Device result = %d\n";

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cout << "Usage: " << argv[0] <<" <xclbin>" << std::endl;
    return EXIT_FAILURE;
  }

  char* xclbinFilename = argv[1];

  // Compute the size of array in bytes
  size_t size_in_bytes = DATA_SIZE * sizeof(int);

  
}
