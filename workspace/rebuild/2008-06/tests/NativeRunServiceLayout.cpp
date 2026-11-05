#include "../native-headers/v8tree/Service.h"
#include "reflection/signal.h"
#include <boost/thread/condition.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/scoped_ptr.hpp>
#define private public
#include "util/RunStateOwner.h"
#undef private
#include <cstddef>
typedef char NativeRunStateOffset[offsetof(RBX::RunService, runState) == 0x1b4 ? 1 : -1];
unsigned donorRunServiceSize = sizeof(RBX::RunService);
unsigned offsets[] = { offsetof(RBX::RunService, runState), offsetof(RBX::RunService, unknown0x1b8),
    offsetof(RBX::RunService, framePeriod), offsetof(RBX::RunService, unknown0x1c8),
    offsetof(RBX::RunService, unknown0x1d0), offsetof(RBX::RunService, unknown0x1d8),
    offsetof(RBX::RunService, unknown0x1e0), offsetof(RBX::RunService, stopwatch),
    offsetof(RBX::RunService, unknownMutex0x2ac), offsetof(RBX::RunService, unknownQueue0x2b4),
    offsetof(RBX::RunService, runDisabled) };
