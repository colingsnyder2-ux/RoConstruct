#include "util/Profiling.h"

void nativeProfilerEnable(bool enabled)
{
    if (enabled)
        RBX::Profiling::Mark::markTlsIndex = TlsAlloc();
}
