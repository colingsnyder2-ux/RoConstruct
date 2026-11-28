// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Lighting2008.h"
#include "util/RunStateOwner.h"

extern "C" char g_0097a99c[];
extern "C" int fn_004651c0(int a1);

namespace RBX {

// INFERRED: the stored field is colorShiftBottom, despite the function name.
void Lighting::setAmbientBottom(G3D::Color3 value)
{
	if (value != colorShiftBottom)
	{
		colorShiftBottom = value;
		raisePropertyChanged(*reinterpret_cast<const Reflection::PropertyDescriptor*>(g_0097a99c));
		fireLightingChanged(false);
		RunService* runService = reinterpret_cast<RunService*>(fn_004651c0(reinterpret_cast<int>(this)));
		if (runService)
			runService->invalidateRunViews();
	}
}

}
