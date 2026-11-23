// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// 2008-06 native (inactive): ClumpStage::getStageType and SleepStage::getStageType (vtable slot 1). Each is `mov eax, N; ret` in
// the exe (0077d810 CLUMP_STAGE = 2, 007359e0 SLEEP_STAGE = 5), identical-code folded with other constant returners, so the
// native headers only declare them. The vtables of the stage classes reference these symbols (found by the donor-free boot).
#include "v8world/ClumpStage2008.h"
#include "v8world/SleepStage2008.h"

namespace RBX
{
	IStage::StageType ClumpStage::getStageType()
	{
		return CLUMP_STAGE;
	}

	IStage::StageType SleepStage::getStageType()
	{
		return SLEEP_STAGE;
	}
}
