// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Donor-derived TU (rbxgs v8datamodel/ICharacterSubject.cpp) on the native headers with the 2008 compiler; exact functions verified by
// check_native_class.py (inactive range evidence, not identity/layout gated).
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Workspace.h"
#include "v8world/ContactManager.h"
#include "v8world/Primitive.h"

namespace RBX
{
	ICharacterSubject::ICharacterSubject()
		: lastOffset(G3D::Vector3::ZERO),
		  cursorLocked(false),
		  wasOccluded(false),
		  hasGoalInFocus(false)
	{
	}

	G3D::CoordinateFrame ICharacterSubject::getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal)
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
		G3D::Vector3 focusToGoal = cameraGoal.translation - cameraFocus.translation;

		float currentDistance = focusToGoal.magnitude();
		float newDistance = Camera::getNewZoomDistance(currentDistance, in);

		newDistance = G3D::min(400.0f, newDistance);

		if (newDistance == currentDistance)
			return false;

		focusToGoal.y = 0.0f;
		focusToGoal.unitize();
		focusToGoal.y = newDistance * 0.03f;

		cameraGoal.translation = focusToGoal.direction() * newDistance + cameraFocus.translation;

		return true;
	}

	//98.58% match
	bool ICharacterSubject::testOcclusion(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, float& distance)
	{
		ContactManager* contactManager = getContactManager();
		if (contactManager)
		{
			std::vector<const Primitive*> ignorePrims;
			getIgnorePrims(ignorePrims);

			G3D::CoordinateFrame manLookCamera = getFocusLookingAtGoal(cameraFocus, cameraGoal);
			G3D::Vector3 pointOnMan = manLookCamera.leftVector();

			int hits = 0;
			float originalDistance = (cameraGoal.translation - cameraFocus.translation).magnitude();
			distance = originalDistance;

			for (int x = -2; x <= 2; x += 2)
			{
				G3D::Vector3 r = manLookCamera.translation + pointOnMan * (float)x;
				G3D::Ray manToCamera = G3D::Ray::fromOriginAndDirection(r, cameraGoal.translation - r);

				G3D::Vector3 hitPoint;
				if (contactManager->getHit(manToCamera, &ignorePrims, NULL, hitPoint))
				{
					hits++;
					float thisDistance = (hitPoint - r).magnitude();
					distance = G3D::min(distance, thisDistance);
				}
			}

			if (hits > 1)
			{
				distance -= 1.0f;
				distance = G3D::max(distance, 0.5f);
				distance = G3D::min(distance, 1000.0f);
				return true;
			}
			else
			{
				distance = originalDistance;
				return false;
			}
		}

		return false;
	}

	void ICharacterSubject::onHeartBeat(G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus)
	{
		if ((cameraGoal.translation - cameraFocus.translation).magnitude() < 2.75f)
		{
			Instance* thisInstance = dynamic_cast<Instance*>(this);
			if (ControllerService* controllerService = ServiceProvider::find<ControllerService>(thisInstance))
			{
				if (Workspace* workspace = ServiceProvider::find<Workspace>(thisInstance))
				{
					UserInputBase* device = controllerService->getHardwareDevice();
					if (device)
					{
						device->centerCursor();
						device->setWrapMode(UserInputBase::WRAP_CENTER);
						cursorLocked = true;
					}
				}
			}
		}
		else
		{
			Instance* thisInstance = dynamic_cast<Instance*>(this);
			if (ControllerService* controllerService = ServiceProvider::find<ControllerService>(thisInstance))
			{
				if (Workspace* workspace = ServiceProvider::find<Workspace>(thisInstance))
				{
					UserInputBase* device = controllerService->getHardwareDevice();
					if (device && cursorLocked)
					{
						if (!workspace->getInMouselookMode())
							device->setWrapMode(UserInputBase::WRAP_AUTO);

						cursorLocked = false;
					}
				}
			}
		}

		float angle = 0.0f;

		if (cursorLocked)
		{
			G3D::Vector3 v = cameraFocus.translation - cameraGoal.translation;
			v.y = 0.0f;
			v = v.direction();

			angle = Math::angleToE0(G3D::Vector2(v.z, v.x));
		}

		cameraSetWalkOrientation(angle, !cursorLocked);
	}

	// 00641800 (1085 bytes; vtable 0083d39c, ICameraSubject slot 5). No donor body. Close to the subject (< 2.75, the
	// constant 0084a5f8 that onHeartBeat also uses) the goal follows the focus; otherwise the focus offset is smoothed
	// (focusOffsetERA +0x18 pushAndGetAverage 00666290, focusERA +0x8 getAverage 006662d0, movement * 16 /= 30 through
	// Vector3::operator/= 005183c0), the goal keeps its horizontal distance (Vector3::xz 005185f0, Vector2::direction
	// 005cbe70) and its height offset, and goalInFocus +0x48 is stored in Math::getFocusSpace 005dec60 space
	// (pointToObjectSpace 00501ca0). Then occlusion: goalFromDistance 00641280, testOcclusion 00641530, wasOccluded
	// +0x3d, unoccludedDistance +0x40, tellCameraNear (slot 8). getLocation is ILocation slot 0 through the vbptr +4;
	// getIntendedMovementVector slot 9, getIntendedRotationAboutYAxis slot 10 (result unused), rotationERA +0x34
	// getAverage 00666270 / pushAndGetAverage 00666250 (results unused), CoordinateFrame::getHeading (getColumn 00513240).
	void ICharacterSubject::stepGoalAndFocus(G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus, bool cameraExternallyAdjusted)
	{
		float distance = 0.0f;
		G3D::Vector3 offset = cameraFocus.translation - cameraGoal.translation;

		if ((cameraGoal.translation - cameraFocus.translation).magnitude() < 2.75f)
		{
			G3D::Vector3 oldFocus = cameraFocus.translation;
			cameraFocus = getLocation();
			G3D::Vector3 focusMoved = cameraFocus.translation - oldFocus;
			cameraGoal.translation += focusMoved;
		}
		else
		{
			cameraFocus = getLocation();

			G3D::Vector3 movement = getIntendedMovementVector() * 16.0f;
			movement /= 30.0f;

			G3D::Vector3 focusDelta = cameraFocus.translation - focusERA.getAverage() - movement;
			focusDelta.y = 0.0f;
			G3D::Vector3 focusOffset = focusOffsetERA.pushAndGetAverage(focusDelta);
			focusERA.pushAndGetAverage(cameraFocus.translation);

			float rotation = getIntendedRotationAboutYAxis(); // INFERRED: result unused by the target
			G3D::CoordinateFrame location = getLocation();
			float heading = location.getHeading();
			float oldHeading = rotationERA.getAverage();       // INFERRED: result unused by the target
			rotationERA.pushAndGetAverage(heading);

			G3D::CoordinateFrame focusSpace = Math::getFocusSpace(cameraFocus);

			cameraGoal.translation += focusOffset;

			distance = offset.xz().length();
			G3D::Vector2 direction = (cameraFocus.translation.xz() - cameraGoal.translation.xz()).direction();
			cameraGoal.translation = cameraFocus.translation - G3D::Vector3(direction.x * distance, offset.y, direction.y * distance);

			goalInFocus = focusSpace.pointToObjectSpace(cameraGoal.translation);
			hasGoalInFocus = true;
		}

		G3D::CoordinateFrame unoccludedGoal = wasOccluded ? goalFromDistance(cameraFocus, cameraGoal, unoccludedDistance) : cameraGoal;

		float occludedDistance;
		bool occluded = testOcclusion(cameraFocus, unoccludedGoal, occludedDistance);
		if (occluded)
		{
			if (!wasOccluded)
				unoccludedDistance = offset.magnitude();

			cameraGoal = goalFromDistance(cameraFocus, cameraGoal, occludedDistance);
		}
		else if (wasOccluded)
		{
			cameraGoal = unoccludedGoal;
		}

		wasOccluded = occluded;
		tellCameraNear(occludedDistance);
	}
}
