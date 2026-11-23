#include "v8datamodel/ForceField.h"
#include "v8datamodel/PartInstance.h"
#include "AppDraw/Draw.h"
#include <boost/bind.hpp>
#include "v8datamodel/Workspace.h"

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

	template<> Reflection::ClassDescriptor& Reflection::Described<ForceField, sForceField,
		FactoryProduct<ForceField, Instance, sForceField> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), sForceField);
		return descriptor;
	}
}

using namespace RBX;

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
	bool ForceField::hasForceField(Instance* instance)
	{
		for (size_t i = 0; i < instance->numChildren(); ++i)
		{
			if (dynamic_cast<ForceField*>(instance->getChild(i)))
				return true;
		}

		return false;
	}

	bool ForceField::isProtectedRecursive(Instance* instance)
	{
		if (hasForceField(instance))
			return true;

		Instance* parent = instance->getParent();
		if (parent && !dynamic_cast<Workspace*>(parent))
			return isProtectedRecursive(parent);

		return false;
	}

	ForceField::ForceField()
		: rendered(false),
		  sparkleCycle(0)
	{
		setName("ForceField");
	}

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
}

template class boost::_bi::value<RBX::Adorn *>;

template void RBX::Name::callDoDeclare<RBX::sForceField>();
