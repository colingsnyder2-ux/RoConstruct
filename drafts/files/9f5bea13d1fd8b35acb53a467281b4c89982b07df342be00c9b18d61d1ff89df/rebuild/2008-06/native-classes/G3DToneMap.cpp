// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <GLG3D/ToneMap.h>

namespace G3D
{
	void ToneMap::setEnabled(bool e)
	{
		if (e == mEnabled)
			return;
		mEnabled = e;
	}

	LightingParameters ToneMap::prepareLightingParameters(const LightingParameters& L) const
	{
		bool on = mEnabled && (profile != NO_TONE);
		double lightScale = on ? 0.75 : 1.0;
		LightingParameters params = L;
		params.emissiveScale *= lightScale;
		params.skyAmbient *= on ? 0.5 : 1.0;
		params.diffuseAmbient *= lightScale;
		params.lightColor *= lightScale;
		params.ambient *= lightScale;
		return params;
	}
}
