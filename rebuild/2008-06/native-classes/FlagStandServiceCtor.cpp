// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native RBX::FlagStandService::FlagStandService 0062ccd0 (inactive), a row of the original FlagStand /
// FlagStandService unit (0062b8f0..0062cf40). FlagStandService.cpp belongs to another contributor, so this row has
// its own unit (flags from native-classes/FlagStand.cpp). Identity: the constructor sets the FlagStandService vtable
// ??_7FlagStandService@RBX@@6B@ 008461ec at +0 after DescribedCreatable<FlagStandService, Instance,
// sFlagStandService>() 0062c820, constructs the flagStands list at +0x130 (list ctor 0061a200), then setName
// (0055af90) with "FlagStandService" (00845f18) and Instance::propArchivable (00973e8c) setValue false (slot 3).
// Shape: 2007 openrbx v8datamodel/FlagStand.cpp FlagStandService::FlagStandService.
#include "v8datamodel/FlagStandService.h"

namespace RBX
{
	const char sFlagStandService[] = "FlagStandService"; // 00845f18 (mangled $1?sFlagStandService@2@3QBDB)

	// 0062ccd0
	FlagStandService::FlagStandService()
	{
		setName(sFlagStandService);
		propArchivable.setValue(this, false);
	}
}
