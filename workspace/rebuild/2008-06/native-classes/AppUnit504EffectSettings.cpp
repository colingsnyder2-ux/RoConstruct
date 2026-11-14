// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native EffectSettings static accessors (inactive).
#include "AppUnit504/RenderEffects.h"
#include <memory>

namespace RBX
{
	namespace Render
	{
		G3D::ToneMap* EffectSettings::getToneMap()
		{
			static std::auto_ptr<G3D::ToneMap> toneMap(new G3D::ToneMap());
			return toneMap.get();
		}

		DepthBlur* EffectSettings::getDepthBlur()
		{
			static std::auto_ptr<DepthBlur> depthBlur(new DepthBlur());
			return depthBlur.get();
		}
	}
}
