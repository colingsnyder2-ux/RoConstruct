// =============================================================================
// ModelInstance.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/ModelInstance.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	float ModelInstance::computeFlagHeight() const
	{
		float answer = 6.0f;

		if (primaryPart)
		{
			float primaryPartY = primaryPart->getExtentsWorld().max().y;
			answer = (getExtentsWorld().max().y - primaryPartY) + 6.0f;
		}

		return answer;
	}

	void ModelInstance::setFrontAndTop(const G3D::Vector3& lookVector)
	{
		if (primaryPart)
		{
			G3D::CoordinateFrame lookFrame;
			lookFrame.lookAt(lookVector);
			modelInPrimary = G3D::CoordinateFrame(
				primaryPart->getCoordinateFrame().rotation.transpose() * lookFrame.rotation,
				G3D::Vector3::zero());
			LocalGridExtents.setDirty();
			WorldGridExtents.setDirty();
			FlagHeight.setDirty();
		}
	}
}

namespace RBX
{
void ModelInstance::onDescendentAdded(Instance* instance) {
	PVInstance::onDescendentAdded(instance);
	LocalGridExtents.setDirty();
	WorldGridExtents.setDirty();
	FlagHeight.setDirty();
	if (instance == (Instance*)candidatePrimaryPart.get()) {
		candidatePrimaryPart.reset();
		updatePrimaryPart((PartInstance*)instance);
	}
	shouldRenderSetDirty();
}
void ModelInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance) {
	if (primaryPart == (PartInstance*)instance.get()) primaryPart = 0;
	if (candidatePrimaryPart.get() == (PartInstance*)instance.get()) candidatePrimaryPart.reset();
	LocalGridExtents.setDirty();
	WorldGridExtents.setDirty();
	FlagHeight.setDirty();
	shouldRenderSetDirty();
	PVInstance::onDescendentRemoving(instance);
}
}

template class RBX::ComputeProp<RBX::Extents,RBX::ModelInstance>;
