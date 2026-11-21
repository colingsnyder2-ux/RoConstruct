// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Lighting setters (inactive); evidence in native-headers/v8datamodel/Lighting2008.h.
// 005e22c0 and 005e2370 write the ColorShift_Top (+0x270) and ColorShift_Bottom (+0x27c) groups; 005e2490 writes
// Ambient (+0x28c). The descriptor objects are namespace-scope statics, as in Lighting2008.cpp (prop_Time).
// The comparison is G3D::Color3::operator!= with the argument on the left, as in setShadowColor 005e2030 (the
// per-component || form compiled to 158 of 172 bytes).
// 005e2420 (103 B, float by value, ret 4) is the Brightness setter: compares/stores brightness +0x288, raises desc
// 0097a980, fires event_LightingChanged(false) without the this-null test, then RunService::invalidateRunViews. It
// needs a 'void setBrightness(float)' declaration in Lighting2008.h (not owned by this unit), so it is not written here.
#include "v8datamodel/Lighting2008.h"
#include "v8datamodel/Sky.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	// INFERRED: descriptor names and the "Appearance" category follow the donor Lighting pattern; the binary's
	// initializer strings for ColorShift_Top / ColorShift_Bottom are not recorded in the evidence yet.
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ColorShiftTop("ColorShift_Top", "Appearance", &Lighting::getColorShiftTop, &Lighting::setColorShiftTop, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_ColorShiftBottom("ColorShift_Bottom", "Appearance", &Lighting::getColorShiftBottom, &Lighting::setColorShiftBottom, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Lighting, G3D::Color3> desc_Ambient("Ambient", "Appearance", &Lighting::getAmbient, &Lighting::setAmbient, Reflection::PropertyDescriptor::STANDARD);

	// 005e22c0: Color3 by value (ret 0xc); compares r, g, b with +0x270, stores, raises desc 0097a900, fires
	// event_LightingChanged(false), then ServiceProvider::find<RunService> and invalidateRunViews 00555350.
	void Lighting::setColorShiftTop(G3D::Color3 value)
	{
		if (value != colorShiftTop)
		{
			colorShiftTop = value;

			raisePropertyChanged(desc_ColorShiftTop);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// 005e2370: same shape as 005e22c0 for colorShiftBottom (+0x27c), raises desc 0097a99c.
	void Lighting::setColorShiftBottom(G3D::Color3 value)
	{
		if (value != colorShiftBottom)
		{
			colorShiftBottom = value;

			raisePropertyChanged(desc_ColorShiftBottom);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}

	// 005e2490: Color3 by value (ret 0xc); compares r, g, b with ambient +0x28c, stores, raises desc 0097aa74,
	// fires event_LightingChanged(false), then RunService::invalidateRunViews.
	void Lighting::setAmbient(G3D::Color3 value)
	{
		if (value != ambient)
		{
			ambient = value;

			raisePropertyChanged(desc_Ambient);
			fireLightingChanged(false);
			RunService* runService = ServiceProvider::find<RunService>(this);
			if (runService)
				runService->invalidateRunViews();
		}
	}
}
