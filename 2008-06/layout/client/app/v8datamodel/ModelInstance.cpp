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
			modelInPrimary = G3D::CoordinateFrame(primaryPart->getCoordinateFrame().rotation.transpose() * lookFrame.rotation, G3D::Vector3::zero());
			LocalGridExtents.setDirty();
			WorldGridExtents.setDirty();
			FlagHeight.setDirty();
		}
	}
}

namespace RBX {
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
