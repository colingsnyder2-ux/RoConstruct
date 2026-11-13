#include "v8datamodel/Filters.h"

#include "humanoid/Humanoid.h"
#include "network/Players.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
// PORT: complete donor filter declaration absent from 2008 header; original method bodies retained.
class IgnoreDescendantsOf : public HitTestFilter
{
protected:
	boost::shared_ptr<Instance> inst; // 0x04

public:
	IgnoreDescendantsOf(Instance* i);

	virtual Result filterResult(const Primitive* testMe) const; // vtable+0x00
};

// FUNCTION: WEBSERVICE 0x10115ac0
// FUNCTION: ROBLOX 0x00662120
bool Unlocked::unlocked(const Primitive* testMe)
{
	return !PartInstance::fromPrimitiveConst(testMe)->getPartLocked();
}

// FUNCTION: WEBSERVICE 0x10115ae0
// FUNCTION: ROBLOX 0x00662140
HitTestFilter::Result PartByLocalCharacter::filterResult(const Primitive* testMe) const
{
	if (character && head) {
		const PartInstance* part = PartInstance::fromPrimitiveConst(testMe);

		if (part->isDescendentOf(character.get())) {
			return head->getIsTransparent() ? IGNORE_PRIM : STOP_TEST;
		}
	}

	return INCLUDE_PRIM;
}

// FUNCTION: ROBLOX 0x00662190
HitTestFilter::Result UnlockedPartByLocalCharacter::filterResult(const Primitive* testMe) const
{
	Result result = PartByLocalCharacter::filterResult(testMe);
	if (result != INCLUDE_PRIM) {
		return result;
	}
	return Unlocked::unlocked(testMe) ? INCLUDE_PRIM : STOP_TEST;
}

// FUNCTION: WEBSERVICE 0x10115b30
// FUNCTION: ROBLOX 0x006621f0
HitTestFilter::Result IgnoreDescendantsOf::filterResult(const Primitive* testMe) const
{
	if (inst) {
		const PartInstance* part = PartInstance::fromPrimitiveConst(testMe);

		if (part->isDescendentOf(inst.get())) {
			return IGNORE_PRIM;
		}
	}

	return INCLUDE_PRIM;
}

// FUNCTION: WEBSERVICE 0x10115b80
// FUNCTION: ROBLOX 0x00662240
PartByLocalCharacter::PartByLocalCharacter(Instance* root)
{
	character = shared_from(Network::Players::findLocalCharacter(root));
	head = shared_from(Humanoid::getHeadFromCharacter(character.get()));
}

// FUNCTION: WEBSERVICE 0x10115ca0
// FUNCTION: ROBLOX 0x00662360
IgnoreDescendantsOf::IgnoreDescendantsOf(Instance* i)
{
	inst = shared_from(i);
}

} // namespace RBX
