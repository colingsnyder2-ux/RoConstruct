// =============================================================================
// ICameraOwner.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/ICameraOwner.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/ICameraOwner.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	void ICameraOwner::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
	{
		for (size_t i = 0; i < cameraIgnoreParts.size(); i++)
		{
			if (!cameraIgnoreParts[i].expired())
			{
				PartInstance* part = cameraIgnoreParts[i].lock().get();
				Primitive* prim = part->getPrimitive();

				primitives.push_back(prim);
			}
		}
	}

	void ICameraOwner::setCameraIgnoreParts(PartInstance* _set)
	{
		std::vector<PartInstance*> temp;
		temp.push_back(_set);

		setCameraIgnoreParts(temp);
	}

	void ICameraOwner::setCameraIgnoreParts(const std::vector<PartInstance*>& _set)
	{
		cameraIgnoreParts.clear();

		for (size_t i = 0; i < _set.size(); i++)
		{
			PartInstance* part = _set[i];
			boost::weak_ptr<PartInstance> ptr = shared_from(part);

			cameraIgnoreParts.push_back(ptr);
		}
	}
}
