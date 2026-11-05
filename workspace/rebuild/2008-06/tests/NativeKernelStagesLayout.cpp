// Layout probe for the inactive native kernel / stage headers (native-headers/v8world/{CleanStage,JointStage,
// SimJobStage,SimJob}2008.h, native-headers/v8kernel/Kernel2008.h). tests/record_native_kernel_stages.py checks each
// size function is `mov eax, imm32; ret` with the size the binary news (World() 005ea920: CleanStage 0x10;
// CleanStage() 0064a310: JointStage 0x50; SleepStage() 0064b8e0: SimJobStage 0x2c; SimJobStage() 0064d300: Kernel
// 0x24; SimJobStage 0064d200: AssemblySimJob 0x28) or that the constructors fill (SimJob 0x24: AssemblySimJob()
// 005e51e0 writes +0x24 after SimJob()). Field offsets are compile-time asserts (NativeKernelStagesLayout is a friend).
#include <stddef.h>
#include "v8world/CleanStage2008.h"
#include "v8world/JointStage2008.h"
#include "v8world/SimJobStage2008.h"
#include "v8world/SimJob2008.h"
#include "v8kernel/Kernel2008.h"

struct NativeKernelStagesLayout
{
	typedef char JointIncomplete[offsetof(RBX::JointStage, incompleteJoints) == 0x10 ? 1 : -1];
	typedef char JointMap[offsetof(RBX::JointStage, jointMap) == 0x30 ? 1 : -1];
	typedef char SimJobStageJobs[offsetof(RBX::SimJobStage, simJobs) == 0x10 ? 1 : -1];
	typedef char SimJobMechanisms[offsetof(RBX::SimJob, mechanisms) == 0x4 ? 1 : -1];
	typedef char SimJobIterator[offsetof(RBX::SimJob, stageIterator) == 0x1c ? 1 : -1];
	typedef char AssemblySimJobAssembly[offsetof(RBX::AssemblySimJob, assembly) == 0x24 ? 1 : -1];
	typedef char KernelInStep[offsetof(RBX::Kernel, inStepCode) == 0xc ? 1 : -1];
	typedef char KernelData[offsetof(RBX::Kernel, kernelData) == 0x10 ? 1 : -1];
	typedef char KernelRealTime[offsetof(RBX::Kernel, realTimeConnectors) == 0x14 ? 1 : -1];
	typedef char KernelProfiling[offsetof(RBX::Kernel, profilingKernel) == 0x20 ? 1 : -1];
};

size_t nativeCleanStageSize() { return sizeof(RBX::CleanStage); }
size_t nativeJointStageSize() { return sizeof(RBX::JointStage); }
size_t nativeSimJobStageSize() { return sizeof(RBX::SimJobStage); }
size_t nativeSimJobSize() { return sizeof(RBX::SimJob); }
size_t nativeAssemblySimJobSize() { return sizeof(RBX::AssemblySimJob); }
size_t nativeKernelSize() { return sizeof(RBX::Kernel); }
