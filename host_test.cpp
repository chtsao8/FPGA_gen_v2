#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define MAX_LENGTH 64

cl_int err;

cl_platform_id platform_id;
cl_platform_id platforms[16];
cl_uint* num_platforms;

cl_device_id devices[16];
cl_device_id device_id;
cl_uint* num_devices;
char cl_device_name[1001];

// host memory pointers
int host_mem_ptr_in[MAX_LENGTH];
int host_mem_ptr_out[MAX_LENGTH];

void populate_mem_ptr(void* mem_ptr) {
  for (int i=0; i<MAX_LENGTH; i++) {
    mem_ptr[i] = i;
  }
}

int load_file_to_memory(const char *filename, char **result)
{
  uint size = 0;
  FILE *f = fopen(filename, "rb");
  if (f == NULL) {
    *result = NULL;
    return -1; // -1 means file opening fail
  }
  fseek(f, 0, SEEK_END);
  size = ftell(f);
  fseek(f, 0, SEEK_SET);
  *result = (char *)malloc(size+1);
  if (size != fread(*result, sizeof(char), size, f)) {
    free(*result);
    return -2; // -2 means file reading fail
  }
  fclose(f);
  (*result)[size] = 0;
  return size;
}

// Gather all Platforms
err = clGetPlatformIDs(16, platforms, &num_platforms);
if (err == CL_SUCCESS) {
  printf("INFO: Found %d platforms\n", num_platforms);
} else {
  printf("Error: Failed to find an OpenCL platform!");
  printf("Test failed\n");
  exit(1);
}

// Find Xilinx Platform
for (uint iplat=0; iplat<num_platforms; iplat++) {
  err = clGetPlatformInfo(platforms[iplat], 
    CL_PLATFORM_VENDOR, 
    1000, 
    (void *)cl_platform_vendor,
    NULL);
  if (strcmp(cl_platform_vendor, "Xilinx") == 0) { 
    // Xilinx Platform found
    printf("Successfully found platform %s\n", cl_platform_vendor);
    platform_id = platforms[iplat];
  }
}

// Gather all Devices
err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR, 
  16, devices, &num_devices);
if (err == CL_SUCCESS) {
  printf("INFO: Found %d devices\n", num_devices);
} else {
  printf("Error: Failed to find an OpenCL device!\n");
  printf("Test failed\n");
  exit(1);
}

// Iterate thru devices to select the target device.
for (uint i=0; i<num_devices; i++) {
  err = clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 1024, cl_device_name, 0);
  if (strcmp(cl_platform_vendor, "Xilinx") == 0) {
    // Target Device found
    printf("Successfully found target device %s\n", cl_device_name);
    device_id = devices[i];
  }
}
// Creates context containing target device. Has a property field I left blank
cl_context context = clCreateContext(0, 1, &device_id, NULL, NULL, &err)
if (err != CL_SUCCESS) {
  printf("Error: Failed to create context for device %s\n", cl_device_name);
  printf("Test failed\n");
  exit(1);
}
cl_command_queue commands = clCreateCommandQueue(context, device_id, 0, &err);
if (err != CL_SUCCESS) {
  printf("Error: Failed to create command queue for device %s\n", cl_device_name);
  printf("Test failed\n");
  exit(1);
}

// Create program
unsigned char *kernelbinary;
char *xclbin = argv[1];
printf("INFO: loading xclbin %s\n", xclbin);
 
int size=load_file_to_memory(xclbin, (char **) &kernelbinary);
size_t size_var = size; 

cl_program program = clCreateProgramWithBinary(context, 1, &device_id, 
           &size_var,(const unsigned char **) &kernelbinary, 
           &status, &err);

// Create kernel
cl_kernel kernel = clCreateKernel(program, "kernel_1", &err);
if (err != CL_SUCCESS) {
  printf("Error: Failed to create kernel");
  printf("Test failed\n");
  exit(1);
}

// Populate input host memory pointer with data
populate_mem_ptr(host_mem_ptr_in);

// Create memory buffers
cl_mem dev_buf_in = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, size, &host_mem_ptr_in, &err);
if (err != CL_SUCCESS) {
  printf("Error: Failed to create input buffer");
  printf("Test failed\n");
  exit(1);
}
cl_mem dev_buf_out = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, size, &host_mem_ptr_out, &err);
if (err != CL_SUCCESS) {
  printf("Error: Failed to create output buffer");
  printf("Test failed\n");
  exit(1);
}
// package mem_objects to send to device
cl_mem mem_objects[2] = {
  dev_buf_in,
  dev_buf_out
};

// Set buffers to kernel arguments
err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &dev_buf_in);
if (err != CL_SUCCESS) {
  printf("Error: Failed to set input kernel argument");
  printf("Test failed\n");
  exit(1);
}
err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &dev_buf_out);
if (err != CL_SUCCESS) {
  printf("Error: Failed to set output kernel argument");
  printf("Test failed\n");
  exit(1);
}

// Copy buffers to device
err = clEnqueueMigrateMemObjects(commands, 2, mem_objects, 0, 0, NULL, NULL);
if (err != CL_SUCCESS) {
  printf("Error: Failed to copy mem objects to device");
  printf("Test failed\n");
  exit(1);
}

// Execution of application on device
err = clEnqueueTask(commands, kernel, 0, NULL, NULL);
if (err != CL_SUCCESS) {
  printf("Error: Failed to enqueue task to device");
  printf("Test failed\n");
  exit(1);
}
clFinish(command_queue); 

// Create event, read memory from device, wait for read to complete, verify results
cl_event readevent;
clEnqueueReadBuffer(command_queue, dev_buf_out, CL_TRUE, 0, size, 
  host_mem_ptr_out, 0, NULL, &readevent);
clWaitForEvents(1, &readevent);

// verify results
// ...

// Post-Processing and FGPA Clean up
clReleaseCommandQueue(commands);
clReleaseContext(context);
clReleaseDevice(device_id); 
clReleaseKernel(kernel);
clReleaseProgram(program);
clReleaseMemObject(dev_buf_in);
clReleaseMemObject(dev_buf_out);
clReleaseEvent(readevent);
