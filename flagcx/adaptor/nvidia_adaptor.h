#ifdef USE_NVIDIA_ADAPTOR

#include "nccl.h"
#include "flagcx.h"
#include "comm.h"
#include "alloc.h"
#include "adaptor.h"
#include <map>
#include <cuda.h>
#include <cuda_runtime.h>
struct flagcxHomoComm {
    ncclComm_t base;
};
struct flagcxStream {
    cudaStream_t base;
};

#define DEVCHECK(func) {                                         \
   int ret = func;                                               \
   if(ret != cudaSuccess) return flagcxUnhandledDeviceError;     \
}

#endif // USE_NVIDIA_ADAPTOR