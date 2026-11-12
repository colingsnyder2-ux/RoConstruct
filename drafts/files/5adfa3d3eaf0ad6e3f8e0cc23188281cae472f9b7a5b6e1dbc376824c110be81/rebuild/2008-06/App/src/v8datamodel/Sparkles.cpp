// 2008-06 native RBX::Sparkles (inactive); evidence in native-headers/v8datamodel/Sparkles.h.
// Verified by tests/record_native_effects.py.
#include "v8datamodel/Sparkles.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	const char sSparkles[] = "Sparkles"; // 0096181c (classDescriptor 005c0780)

	// Template members the shared headers only declare (same definitions as Team.cpp / DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	// Dynamic initializer 007f8be0.
	Reflection::BoundProp<bool, 1> Sparkles::prop_Enabled("Enabled", "Data", &Sparkles::enabled, Reflection::PropertyDescriptor::STANDARD);

	Sparkles::Sparkles()
		: enabled(true)
	{
		setName("Sparkles");
	}

	Sparkles::~Sparkles()
	{
	}

	bool Sparkles::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const PartInstance*>(instance) != 0;
	}

	// 0063d710 (123 bytes): dynamic_cast<PartInstance*>(getParent()) then the two IRenderable
	// vtable calls setObjectToWorldMatrix (+0x38) and sparkle (+0x4c, slot 19).
	void Sparkles::render3dAdorn(Adorn* adorn)
	{
		PartInstance* part = dynamic_cast<PartInstance*>(getParent());
		if (part && enabled)
		{
			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(part->getCoordinateFrame().translation));
			adorn->sparkle();
		}
	}
}
