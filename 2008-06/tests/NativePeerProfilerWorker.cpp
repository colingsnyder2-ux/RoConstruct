#include <windows.h>
#include "util/Profiling.h"
typedef char CodeProfilerSize[sizeof(RBX::Profiling::CodeProfiler)==0xc048?1:-1];
typedef char CountProfilerSize[sizeof(RBX::Profiling::CountProfiler)==0xc048?1:-1];
RBX::Profiling::CodeProfiler* NativePeerPacketsProfilerWorker() { return new RBX::Profiling::CodeProfiler("Packets Thread"); }
