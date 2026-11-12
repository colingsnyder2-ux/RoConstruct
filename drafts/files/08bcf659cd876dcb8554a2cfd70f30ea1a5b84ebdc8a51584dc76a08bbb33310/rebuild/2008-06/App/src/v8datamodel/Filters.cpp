// 2008-06 native hit-test filters (inactive); evidence in native-headers/v8datamodel/Filters2008.h.
// Verified by tests/record_native_hit_filters.py. The original unit is 006601c0..00660544 (the inline
// PartInstance::getIsTransparent 006601c0 is emitted first). The PartByLocalCharacter constructor needs a
// Humanoid::getHeadFromCharacter declaration that no native header provides yet, so it compiles only under
// NATIVE_HIT_FILTERS_PENDING against the declaration-only overlay tests/NativeHitTestFilterPendingHumanoid.h.
#include "v8datamodel/Filters2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Players.h"
#include "humanoid/Humanoid.h"

namespace RBX
{
	// 006601f0
	bool Unlocked::unlocked(const Primitive* testMe)
	{
		return !PartInstance::fromPrimitiveConst(testMe)->getPartLocked();
	}

	// 00660210
	FilterCharacterOcclusion::FilterCharacterOcclusion(int)
	{
	}

	// 00660220: the 0.95f literal is 008378a4; transparency is the stored (Xml) value, PartInstance +0x1e8.
	HitTestFilter::Result FilterCharacterOcclusion::filterResult(const Primitive* testMe) const
	{
		const PartInstance* part = PartInstance::fromPrimitiveConst(testMe);
		if (part->getCanCollide() && !(part->getTransparencyXml() > 0.95f))
			return HitTestFilter::INCLUDE_PRIM;
		return HitTestFilter::IGNORE_PRIM;
	}

	// 00660260
	HitTestFilter::Result PartByLocalCharacter::filterResult(const Primitive* testMe) const
	{
		if (character && head)
		{
			const PartInstance* p = PartInstance::fromPrimitiveConst(testMe);

			if (p->isDescendentOf(character.get()))
			{
				return head->getIsTransparent() ? HitTestFilter::IGNORE_PRIM : HitTestFilter::STOP_TEST;
			}
		}

		return HitTestFilter::INCLUDE_PRIM;
	}

	// 006602b0: PartByLocalCharacter::filterResult and Unlocked::unlocked are inlined.
	HitTestFilter::Result UnlockedPartByLocalCharacter::filterResult(const Primitive* testMe) const
	{
		HitTestFilter::Result result = PartByLocalCharacter::filterResult(testMe);
		if (result == HitTestFilter::INCLUDE_PRIM)
			return Unlocked::unlocked(testMe) ? HitTestFilter::INCLUDE_PRIM : HitTestFilter::STOP_TEST;
		return result;
	}

	// 00660320: the parent test is expanded one level before the out-of-line Instance::isDescendentOf 00422ae0.
	HitTestFilter::Result FilterStairs::filterResult(const Primitive* testMe) const
	{
		if (model)
		{
			const PartInstance* part = PartInstance::fromPrimitiveConst(testMe);
			const Instance* ancestor = model.get();
			const Instance* parent = part->getParent();
			if (ancestor == parent || (parent && parent->isDescendentOf(ancestor)))
				return HitTestFilter::IGNORE_PRIM;
			if (!part->getCanCollide())
				return HitTestFilter::IGNORE_PRIM;
		}
		return HitTestFilter::INCLUDE_PRIM;
	}

	// 00660380
	PartByLocalCharacter::PartByLocalCharacter(Instance* root)
	{
		character = shared_from(Network::Players::findLocalCharacter(root));
		head = shared_from(Humanoid::getHeadFromCharacter(character.get()));
	}

	// 006604a0
	FilterStairs::FilterStairs(Instance* model)
	{
		this->model = shared_from(model);
	}
}
