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
}
