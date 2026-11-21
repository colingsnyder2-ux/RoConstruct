#include "v8datamodel/Filters2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Players.h"
#include "humanoid/Humanoid.h" // native Humanoid::getHeadFromCharacter 005d75a0 (PartByLocalCharacter 00660380)

namespace RBX
{
	bool Unlocked::unlocked(const Primitive* testMe)
	{
		return !PartInstance::fromPrimitiveConst(testMe)->getPartLocked();
	}

	FilterCharacterOcclusion::FilterCharacterOcclusion(int)
	{
	}

	HitTestFilter::Result FilterCharacterOcclusion::filterResult(const Primitive* testMe) const
	{
		const PartInstance* part = PartInstance::fromPrimitiveConst(testMe);
		if (part->getCanCollide() && !(part->getTransparencyXml() > 0.95f))
			return HitTestFilter::INCLUDE_PRIM;
		return HitTestFilter::IGNORE_PRIM;
	}

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

	HitTestFilter::Result UnlockedPartByLocalCharacter::filterResult(const Primitive* testMe) const
	{
		HitTestFilter::Result result = PartByLocalCharacter::filterResult(testMe);
		if (result == HitTestFilter::INCLUDE_PRIM)
			return Unlocked::unlocked(testMe) ? HitTestFilter::INCLUDE_PRIM : HitTestFilter::STOP_TEST;
		return result;
	}

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

	PartByLocalCharacter::PartByLocalCharacter(Instance* root)
	{
		character = shared_from(Network::Players::findLocalCharacter(root));
		head = shared_from(Humanoid::getHeadFromCharacter(character.get()));
	}

	FilterStairs::FilterStairs(Instance* model)
	{
		this->model = shared_from(model);
	}
}
