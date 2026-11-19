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
		float dx = cameraGoal.translation.x - cameraFocus.translation.x;
		float dy = cameraGoal.translation.y - cameraFocus.translation.y;
		float dz = cameraGoal.translation.z - cameraFocus.translation.z;
		cursorLocked = sqrtf(dx * dx + dy * dy + dz * dz) < 2.75f;

		Instance* thisInstance = dynamic_cast<Instance*>(this);
		if (Workspace* workspace = ServiceProvider::find<Workspace>(thisInstance))
			workspace->setInMouselookMode(cursorLocked);

		float angle = 0.0f;
		if (cursorLocked)
		{
			float vx = cameraFocus.translation.x - cameraGoal.translation.x;
			float vz = cameraFocus.translation.z - cameraGoal.translation.z;
			float inv = 1.0f / sqrtf(vx * vx + vz * vz);
			angle = Math::angleToE0(G3D::Vector2(vz * inv, vx * inv));
		}

		cameraSetWalkOrientation(angle, !cursorLocked);
	}

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
