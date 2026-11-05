// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_fd60914847771c1b.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h","roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/Explosion.h"
namespace RBX {
static Reflection::PropDescriptor<Explosion, float> propBlastRadius("BlastRadius", "Data", &Explosion::getBlastRadius, &Explosion::setBlastRadius, Reflection::PropertyDescriptor::STANDARD);
Explosion::Explosion()
		: blastRadius(4.0f),
		  blastPressure(500000.0f),
		  age(0.0f)
	{
		setName("Explosion");
	}
bool Explosion::askSetParent(const Instance* instance) const
	{
		return true;
	}
void Explosion::setBlastRadius(float _blastRadius)
	{
		float newRadius = G3D::clamp(_blastRadius, 0.0f, 100.0f);
		if (blastRadius != newRadius)
		{
			blastRadius = newRadius;
			raisePropertyChanged(propBlastRadius);
		}
	}
void Explosion::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<RunService, Stepped>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);

		Instance::onServiceProvider(oldProvider, newProvider);

		Notifier<RunService, Stepped>::connect(ServiceProvider::find<RunService>(newProvider), this);
	}
}
