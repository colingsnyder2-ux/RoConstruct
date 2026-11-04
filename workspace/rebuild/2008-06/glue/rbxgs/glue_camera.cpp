// Rebuild glue: ICharacterSubject::stepGoalAndFocus, which rbxgs declares but never defines (it
// replaces an empty stub). The camera focus follows the character (a little above its location), the
// camera keeps its offset from the focus, and walls between the two pull the camera in, using the
// rbxgs helpers testOcclusion/goalFromDistance. Behavioural reconstruction, not byte-verified.
#include "v8datamodel/ICharacterSubject.h"

namespace RBX
{
	void ICharacterSubject::stepGoalAndFocus(G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus, bool cameraExternallyAdjusted)
	{
		G3D::Vector3 offset = cameraGoal.translation - cameraFocus.translation;
		if (!cameraExternallyAdjusted && wasOccluded)
			offset = lastOffset;  // keep the unoccluded framing while a wall is in the way

		cameraFocus = G3D::CoordinateFrame(cameraFocus.rotation, getLocation().translation + G3D::Vector3(0.0f, 1.5f, 0.0f));
		cameraGoal.translation = cameraFocus.translation + offset;

		float distance;
		if (testOcclusion(cameraFocus, cameraGoal, distance))
		{
			if (!wasOccluded)
				lastOffset = offset;
			wasOccluded = true;
			cameraGoal = goalFromDistance(cameraFocus, cameraGoal, distance);
		}
		else
		{
			wasOccluded = false;
			unoccludedDistance = offset.magnitude();
			lastOffset = offset;
		}
		cameraGoal.lookAt(cameraFocus.translation);
	}
}
