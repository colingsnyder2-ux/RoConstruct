// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// RBX::ICharacterSubject camera-subject bodies (original unit near 0x641240).
// Layout from the binary: +0x00 vfptr, +0x04 vbptr (virtual ILocation),
// +0x08 focusERA, +0x18 focusOffsetERA, +0x34 rotationERA, +0x3c cursorLocked,
// +0x3d wasOccluded, +0x40 unoccludedDistance, +0x44 hasGoalInFocus,
// +0x48 goalInFocus (matches native-headers/v8datamodel/ICharacterSubject.h).
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/Camera.h"
#include "util/Math.h"
#include <math.h>

namespace RBX
{
	// 0x00641240
	G3D::CoordinateFrame ICharacterSubject::getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal)
	{
		G3D::CoordinateFrame temp = cameraFocus;
		temp.lookAt(cameraGoal.translation);

		return temp;
	}

	// 0x00641280
	G3D::CoordinateFrame ICharacterSubject::goalFromDistance(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, const float distance)
	{
		G3D::CoordinateFrame manLookCamera = getFocusLookingAtGoal(cameraFocus, cameraGoal);
		G3D::Vector3 newCameraPt = manLookCamera.lookVector() * distance + manLookCamera.translation;

		return G3D::CoordinateFrame(G3D::Matrix3::identity(), newCameraPt);
	}

	// 0x00641390
	bool ICharacterSubject::zoom(const float in, G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus)
	{
		// The 2008 build zooms the unoccluded goal while the camera is pulled in by an occluder.
		G3D::CoordinateFrame testGoal = wasOccluded ? goalFromDistance(cameraFocus, cameraGoal, unoccludedDistance) : cameraGoal;

		G3D::Vector3 focusToGoal = testGoal.translation - cameraFocus.translation;

		float currentDistance = focusToGoal.magnitude();
		float newDistance = G3D::min(400.0f, Camera::getNewZoomDistance(currentDistance, in));

		if (newDistance == currentDistance)
			return false;

		focusToGoal.y = 0.0f;
		focusToGoal.unitize();
		focusToGoal.y = newDistance * 0.03f;

		testGoal.translation = focusToGoal.direction() * newDistance + cameraFocus.translation;

		if (wasOccluded)
			unoccludedDistance = (testGoal.translation - cameraFocus.translation).magnitude();
		else
			cameraGoal = testGoal;

		return true;
	}

	// 0x00641800
	// PARKED (not byte-exact, 1145B candidate vs 1085B target): control flow, callees and
	// vtable slots match, but the target calls G3D::Vector2::direction out of line
	// (0x005cbe70, also out of line at both Camera call sites 0x5ccc62/0x5ccdac) while
	// this compile inlines it, which shifts the frame (0x11c vs 0x10c) and register use.
	// Rejected: Vector2(x, 0, z) argument form, fastDirection(), unnamed getLocation temp.
	void ICharacterSubject::stepGoalAndFocus(G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus, bool cameraExternallyAdjusted)
	{
		G3D::Vector3 goalToFocus = cameraFocus.translation - cameraGoal.translation;

		if ((cameraGoal.translation - cameraFocus.translation).magnitude() < 2.75f)
		{
			G3D::Vector3 oldFocus = cameraFocus.translation;
			cameraFocus = getLocation();
			cameraGoal.translation += cameraFocus.translation - oldFocus;
		}
		else
		{
			cameraFocus = getLocation();

			G3D::Vector3 movement = getIntendedMovementVector() * 16.0f;
			movement /= 30.0f;

			G3D::Vector3 offset = cameraFocus.translation - focusERA.getAverage() - movement;
			offset.y = 0.0f;
			offset = focusOffsetERA.pushAndGetAverage(offset);
			focusERA.pushAndGetAverage(cameraFocus.translation);

			getIntendedRotationAboutYAxis();

			G3D::CoordinateFrame location = getLocation();
			G3D::Vector3 look = location.rotation.getColumn(2);
			rotationERA.getAverage();
			rotationERA.pushAndGetAverage(-atan2(-look.x, look.z));

			G3D::CoordinateFrame focusSpace = Math::getFocusSpace(cameraFocus);

			cameraGoal.translation += offset;

			float horizontalDistance = goalToFocus.xz().length();
			G3D::Vector2 direction;
			direction = (cameraFocus.translation.xz() - cameraGoal.translation.xz()).direction();
			cameraGoal.translation = cameraFocus.translation - G3D::Vector3(direction.x * horizontalDistance, goalToFocus.y, direction.y * horizontalDistance);

			goalInFocus = focusSpace.pointToObjectSpace(cameraGoal.translation);
			hasGoalInFocus = true;
		}

		G3D::CoordinateFrame unoccludedGoal = wasOccluded ? goalFromDistance(cameraFocus, cameraGoal, unoccludedDistance) : cameraGoal;

		float distance;
		bool occluded = testOcclusion(cameraFocus, unoccludedGoal, distance);
		if (occluded)
		{
			if (!wasOccluded)
				unoccludedDistance = goalToFocus.magnitude();

			cameraGoal = goalFromDistance(cameraFocus, cameraGoal, distance);
		}
		else if (wasOccluded)
		{
			cameraGoal = unoccludedGoal;
		}

		wasOccluded = occluded;
		tellCameraNear(distance);
	}
}
