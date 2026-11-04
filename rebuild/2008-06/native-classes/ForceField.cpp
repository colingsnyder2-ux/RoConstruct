// 2008-06 native RBX::ForceField (inactive); evidence in native-headers/v8datamodel/ForceField.h.
// Verified by tests/record_native_debris_forcefield.py (built with /fp:fast: renderPart 0062d200 reuses the 0.0f of
// the transparency compare as the green channel).
// NATIVE_FORCEFIELD_PENDING bodies need declarations the shared headers do not have yet: a complete RBX::Workspace
// (dynamic_cast in askSetParent 0062d090 and the ancestor walk 0062d380) and Instance::visitDescendents
// (0062d400, used by render3dAdorn 0062d570). The recorder builds them against generated copies under
// out/native-layouts/debris-forcefield-pending/.
#include "v8datamodel/ForceField.h"
#include "v8datamodel/PartInstance.h"
#include "AppDraw/Draw.h"
#include <boost/bind.hpp>
#ifdef NATIVE_FORCEFIELD_PENDING
#include "v8datamodel/Workspace.h"
#endif

namespace RBX
{
	char sForceField[] = "ForceField"; // 0095c3a8 (.data; doDeclare 005bf9c0, classDescriptor 005c0400)

	// Template members the shared headers only declare (same definitions as Explosion.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

using namespace RBX;

// 0062d200: bound with the adorn and cycle by render3dAdorn and applied to the parent and each descendant.
static void renderPart(boost::shared_ptr<Instance> instance, Adorn* adorn, int cycle)
{
	if (PartInstance* part = dynamic_cast<PartInstance*>(instance.get()))
	{
		// +0x328 of the 2008 PartInstance (accessor provisional); the original draws when it is non-zero.
		if (part->getTransparencyXml() != 0.0f)
		{
			float a = (cycle < 15 ? cycle : 30 - cycle) * (1.0f / 15.0f);
			Draw::selectionBox(part->getPart(), adorn, G3D::Color4(a, 0.0f, 1.0f - a, 0.5f)); // 00676e00 (Draw.cpp, Color4 overload)
		}
	}
}

namespace RBX
{
	// 0062d310: first half of its function-list row (0x70 bytes).
	bool ForceField::hasForceField(Instance* instance)
	{
		for (size_t i = 0; i < instance->numChildren(); ++i)
		{
			if (dynamic_cast<ForceField*>(instance->getChild(i)))
				return true;
		}

		return false;
	}

#ifdef NATIVE_FORCEFIELD_PENDING
	// 0062d380: second half of the 0062d310 row; the tail recursion is a loop in the original.
	bool ForceField::isProtectedRecursive(Instance* instance)
	{
		if (hasForceField(instance))
			return true;

		Instance* parent = instance->getParent();
		if (parent && !dynamic_cast<Workspace*>(parent))
			return isProtectedRecursive(parent);

		return false;
	}
#endif

	ForceField::ForceField()
		: rendered(false),
		  sparkleCycle(0)
	{
		setName("ForceField");
	}

#ifdef NATIVE_FORCEFIELD_PENDING
	bool ForceField::isProtected(Instance* instance)
	{
		return isProtectedRecursive(instance);
	}

	bool ForceField::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const Workspace*>(instance) == NULL;
	}

	void ForceField::render3dAdorn(Adorn* adorn)
	{
		Instance* parent = getParent();

		if (rendered && !dynamic_cast<Workspace*>(parent))
		{
			sparkleCycle = (sparkleCycle + 1) % 30;
			parent->visitDescendents(boost::bind(&renderPart, _1, adorn, sparkleCycle));
			renderPart(shared_from(parent), adorn, sparkleCycle);
		}

		rendered = true;
	}
#endif
}
