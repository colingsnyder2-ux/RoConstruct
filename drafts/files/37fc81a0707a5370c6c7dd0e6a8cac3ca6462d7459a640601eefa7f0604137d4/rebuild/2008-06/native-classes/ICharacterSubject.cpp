// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/Camera.h"
namespace RBX {
ICharacterSubject::ICharacterSubject()
    : lastOffset(G3D::Vector3::ZERO), cursorLocked(false), wasOccluded(false), hasGoalInFocus(false)
{
}
// Original goalFromDistance calls this helper at 00641293.
__declspec(noinline) G3D::CoordinateFrame ICharacterSubject::getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal)
{
    G3D::CoordinateFrame temp = cameraFocus;
    temp.lookAt(cameraGoal.translation);
    return temp;
}
G3D::CoordinateFrame ICharacterSubject::goalFromDistance(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, const float distance)
{
    G3D::CoordinateFrame manLookCamera = getFocusLookingAtGoal(cameraFocus, cameraGoal);
    G3D::Vector3 newCameraPt = manLookCamera.lookVector() * distance + manLookCamera.translation;
    return G3D::CoordinateFrame(G3D::Matrix3::identity(), newCameraPt);
}
	bool ICharacterSubject::zoom(const float in, G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus)
	{
		// INFERRED: 006413a7/006413c3 select the unoccluded goal when wasOccluded.
		G3D::CoordinateFrame newGoal = wasOccluded ? goalFromDistance(cameraFocus, cameraGoal, unoccludedDistance) : cameraGoal;
		G3D::Vector3 focusToGoal = newGoal.translation - cameraFocus.translation;

		float currentDistance = focusToGoal.magnitude();
		float newDistance = Camera::getNewZoomDistance(currentDistance, in);

		float clampedDistance = G3D::min(400.0f, newDistance);

		if (clampedDistance == currentDistance)
			return false;

		focusToGoal.y = 0.0f;
		focusToGoal.unitize();
		focusToGoal.y = clampedDistance * 0.03f;

		newGoal.translation = focusToGoal.direction() * clampedDistance + cameraFocus.translation;
		// INFERRED: 006414e1 branches to distance storage or full goal assignment.
		if (wasOccluded)
			unoccludedDistance = (newGoal.translation - cameraFocus.translation).magnitude();
		else
			cameraGoal = newGoal;

		return true;
	}

}
