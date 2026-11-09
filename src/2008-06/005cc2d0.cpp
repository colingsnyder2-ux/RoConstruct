// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_camera_native_owner_family_b5977bd610cfbe4d.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/Camera.h", "../roc_camera_native_header_db0bf117fdeefdc1.cpp")
#undef _RELEASEASSERT
#include "v8datamodel/Camera.h"
#include "util/Math.h"
#include "v8datamodel/ICameraOwner.h"
namespace RBX {
void Camera::tellCameraMoved() {
 if (ICameraOwner* owner = getCameraOwner()) owner->cameraMoved();
}


	void Camera::setGCameraCoordinateFrame(const G3D::CoordinateFrame& coord)
	{
		if (Math::legalCameraCoord(coord))
		{
			(*(G3D::GCamera*)((char*)this+0x130)).setCoordinateFrame(coord);
		}
		else
		{
			RBXASSERT(false);
		}
	}

	void Camera::lookAt(const G3D::Vector3& point)
	{
		(*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation = point;
		(*(G3D::CoordinateFrame*)((char*)this+0x174)).lookAt(point);
	}

	void Camera::getHeadingElevationDistance(float& heading, float& elevation, float& distance)
	{
		Math::getHeadingElevation((*(G3D::CoordinateFrame*)((char*)this+0x174)), heading, elevation);
		distance = goalToFocusDistance();
	}

	bool Camera::setDistanceFromTarget(float newDistance)
	{
		G3D::Vector3 lookVector = (*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation - (*(G3D::CoordinateFrame*)((char*)this+0x174)).translation;
		float currentDistance = lookVector.magnitude();

		const float min = distanceMin();
		const float max = distanceMax();

		if (newDistance < min && currentDistance == min)
			return false;
		
		if (newDistance > max && currentDistance == max)
			return false;

		newDistance = G3D::min(max, G3D::max(min, newDistance));
		
		lookVector *= newDistance;
		(*(G3D::CoordinateFrame*)((char*)this+0x174)).translation = (*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation - (lookVector / currentDistance);

		tellCameraMoved();

		return true;
	}

	bool Camera::nonCharacterZoom(float in)
	{
		G3D::Vector3 lookVector = (*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation - (*(G3D::CoordinateFrame*)((char*)this+0x174)).translation;

		float currentDistance = lookVector.magnitude();
		float newZoomDistance = getNewZoomDistance(currentDistance, in);

		if (newZoomDistance == currentDistance)
			return false;

		(*(G3D::CoordinateFrame*)((char*)this+0x174)).translation -= lookVector * (newZoomDistance / currentDistance - 1.0f);

		tellCameraMoved();

		return true;
	}

	bool Camera::characterZoom(float in)
	{
		G3D::Vector3 focusToGoal = (*(G3D::CoordinateFrame*)((char*)this+0x174)).translation - (*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation;

		float currentDistance = focusToGoal.magnitude();

		float maxDistance = distanceMaxCharacter();
		float newDistance = getNewZoomDistance(currentDistance, in);
		newDistance = G3D::min(newDistance, maxDistance);

		if (newDistance == currentDistance)
			return false;

		focusToGoal.y = 0.0;
		focusToGoal.unitize();
		focusToGoal.y = newDistance * 0.03f;

		(*(G3D::CoordinateFrame*)((char*)this+0x174)).translation = focusToGoal.direction() * newDistance + (*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation;

		return true;
	}

	void Camera::panRadians(float angle)
	{
		RBXASSERT(angle > -100);
		RBXASSERT(angle < 100);

		if (angle != 0)
		{
			float heading, elevation, distance;

			getHeadingElevationDistance(heading, elevation, distance);
			heading = Math::radWrap(heading + angle);
			setHeadingElevationDistance(heading, elevation, distance);

			tellCameraMoved();
		}
	}

	bool Camera::tiltRadians(float angle)
	{
		if (angle != 0)
		{
			float heading, elevation, distance;
			getHeadingElevationDistance(heading, elevation, distance);

			static float rad = G3D::toRadians(81);
			float newElevation = G3D::clamp(elevation + angle, -rad, rad);

			if (elevation != newElevation)
			{
				setHeadingElevationDistance(heading, newElevation, distance);
				tellCameraMoved();
				return true;
			}
		}

		return false;
	}

	void Camera::tryZoomExtents(float low, float current, float high, const Extents& extents, const G3D::Rect2D& viewPort)
	{
		RBXASSERT(current >= low);
		RBXASSERT(current <= high);

		if (high - low < 0.1)
			return;

		setDistanceFromTarget(current);
		updateGoal();
		goalToCamera();

		if (extents.containedByFrustum((*(G3D::GCamera*)((char*)this+0x130)).frustum(viewPort)))
		{
			tryZoomExtents(low, (low + current) * 0.5, current, extents, viewPort);
		}
		else
		{
			tryZoomExtents(current, (current + high) * 0.5, high, extents, viewPort);
		}
	}

	void Camera::zoomExtents(Extents extents, const G3D::Rect2D& viewPort, Camera::ZoomType zoomType)
	{
		G3D::CoordinateFrame currentCoord = (*(G3D::GCamera*)((char*)this+0x130)).getCoordinateFrame();
		extents.expand(0.1f);

		if (zoomType != ZOOM_CHAR_PART_DRAG || (*(CameraType*)((char*)this+0x1d4)) == CUSTOM_CAMERA)
		{
			if ((*(CameraType*)((char*)this+0x1d4)) == FIXED_CAMERA)
			{
				G3D::Vector3 scaler = extents.center() - (*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation;

				(*(G3D::CoordinateFrame*)((char*)this+0x1a4)).translation += scaler;
				(*(G3D::CoordinateFrame*)((char*)this+0x174)).translation += scaler;
			}

			float low;

			if (zoomType == ZOOM_OUT_ONLY || zoomType == ZOOM_CHAR_PART_DRAG)
				low = goalToFocusDistance();
			else
				low = distanceMin();

			float current = goalToFocusDistance();

			RBXASSERT(G3D::isFinite(current));

			if (zoomType == ZOOM_CHAR_PART_DRAG)
				extents.scale(1.1f);

			if (G3D::isFinite(low) && G3D::isFinite(current) && G3D::isFinite(distanceMax()))
				tryZoomExtents(low, current, distanceMax(), extents, viewPort);

			(*(G3D::CoordinateFrame*)((char*)this+0x174)) = (*(G3D::GCamera*)((char*)this+0x130)).getCoordinateFrame();
			setGCameraCoordinateFrame(currentCoord);
			tellCameraMoved();
		}
	}
}
