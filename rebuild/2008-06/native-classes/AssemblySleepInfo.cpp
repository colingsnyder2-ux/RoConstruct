// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 RBX::SleepInfo constructor (inactive). It sits in the v8world Assembly unit range (005e5f30, between
// ??_EMotorJoint 005e5ee0 and Assembly::assemblyPrimEnd 005e5fc0), as in the donor openrbx Assembly.cpp, and is
// therefore out of line for SleepStage::onAssemblyAdded 0064aff0 (call at 0064b034). Defining it in
// SleepStage2008.cpp inlines it there and loses 0064aff0, so it lives in its own unit. Declaration:
// native-headers/v8world/SleepStage2008.h (flags line from SleepStage2008.cpp plus the Assembly unit's /fp:fast).
#include "v8world/SleepStage2008.h"

namespace RBX
{
	// 005e5f30 ??0SleepInfo@RBX@@QAE@XZ (registry): state = 2 (WAKE_PENDING), sleepCount = 0, then the
	// RunningAverageState default (Vector3 zero, Quaternion 0,0,0,1: fldz stores +0x8..+0x1c, fld1 +0x20).
	SleepInfo::SleepInfo()
		: state(Sim::WAKE_PENDING),
		  sleepCount(0)
	{
	}
}
