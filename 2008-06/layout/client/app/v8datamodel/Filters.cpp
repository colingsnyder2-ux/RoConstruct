// =============================================================================
// Filters.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Filters.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
