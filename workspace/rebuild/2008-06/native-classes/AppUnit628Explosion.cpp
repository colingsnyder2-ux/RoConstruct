// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Explosion.h"

namespace RBX
{
	static Reflection::PropDescriptor<Explosion, float> propBlastRadius("BlastRadius", "Data", &Explosion::getBlastRadius, &Explosion::setBlastRadius, Reflection::PropertyDescriptor::STANDARD);

	void Explosion::setBlastRadius(float _blastRadius)
	{
		float newRadius = G3D::clamp(_blastRadius, 0.0f, 100.0f);
		if (blastRadius != newRadius)
		{
			blastRadius = newRadius;
			raisePropertyChanged(propBlastRadius);
		}
	}
}
