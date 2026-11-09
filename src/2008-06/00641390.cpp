// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_characterzoomminexpression0441686f39f83997.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/Camera.h"
namespace RBX {
	bool ICharacterSubject::zoom(const float in, G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus)
	{
		G3D::CoordinateFrame adjustedGoal = wasOccluded ? goalFromDistance(cameraFocus, cameraGoal, unoccludedDistance) : cameraGoal;
		G3D::Vector3 focusToGoal = adjustedGoal.translation - cameraFocus.translation;

		float currentDistance = focusToGoal.magnitude();
		float newDistance = G3D::min(400.0f, Camera::getNewZoomDistance(currentDistance, in));

		if (newDistance == currentDistance)
			return false;

		focusToGoal.y = 0.0f;
		focusToGoal.unitize();
		focusToGoal.y = newDistance * 0.03f;

		adjustedGoal.translation = focusToGoal.direction() * newDistance + cameraFocus.translation;

		if (wasOccluded) unoccludedDistance = (adjustedGoal.translation - cameraFocus.translation).magnitude();
		else cameraGoal = adjustedGoal;
		return true;
	}


}
