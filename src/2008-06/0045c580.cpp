// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8datamodel/ForceField.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/ForceField.h"

#include "appdraw/Draw.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"

#include <boost/bind.hpp>

namespace RBX {

char sForceField[] = "ForceField";

// FUNCTION: WEBSERVICE 0x100e9270
// FUNCTION: ROBLOX 0x00628420
bool ForceField::askSetParent(const Instance* instance) const
{
	return dynamic_cast<const Workspace*>(instance) == NULL;
}

// FUNCTION: WEBSERVICE 0x100e9370
// FUNCTION: ROBLOX 0x00628560
void renderForceField(boost::shared_ptr<Instance> descendent, Adorn* adorn, int cycle)
{
	if (PartInstance* part = dynamic_cast<PartInstance*>(descendent.get())) {
		int value = cycle < 15 ? cycle : 30 - cycle;
		G3D::Color4 color(value / 15.0f, 0.0f, 1.0f - value / 15.0f, 0.5f);
		Draw::selectionBox(part->getPart(), adorn, color);
	}
}

// FUNCTION: WEBSERVICE 0x100e9470
// FUNCTION: ROBLOX 0x00628660
bool containsForceField(Instance* instance)
{
	for (unsigned int i = 0; i < instance->numChildren(); ++i) {
		if (dynamic_cast<ForceField*>(instance->getChild(i))) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100e94f0
// FUNCTION: ROBLOX 0x006286e0
bool ancestorContainsForceField(Instance* instance)
{
	if (containsForceField(instance)) {
		return true;
	}

	Instance* parent = instance->getParent();
	if (parent != NULL && dynamic_cast<Workspace*>(parent) == NULL) {
		return ancestorContainsForceField(parent);
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100e9540
// FUNCTION: ROBLOX 0x00628730
bool ForceField::partInForceField(PartInstance* part)
{
	return ancestorContainsForceField(part);
}

// FUNCTION: WEBSERVICE 0x100e96a0
// FUNCTION: ROBLOX 0x00628890
void ForceField::render3dAdorn(Adorn* adorn)
{
	cycle = (cycle + 1) % 30;

	getParent()->visitDescendents(boost::bind(&renderForceField, _1, adorn, cycle));
}

// FUNCTION: WEBSERVICE 0x100e97f0
// FUNCTION: ROBLOX 0x006289a0
ForceField::ForceField() : cycle(0)
{
	setName("ForceField");
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::ForceField, RBX::Instance, RBX::sForceField>;
template class RBX::Reflection::Described<
	RBX::ForceField,
	RBX::sForceField,
	RBX::FactoryProduct<RBX::ForceField, RBX::Instance, RBX::sForceField> >;
template class RBX::DescribedCreatable<RBX::ForceField, RBX::Instance, RBX::sForceField>;
