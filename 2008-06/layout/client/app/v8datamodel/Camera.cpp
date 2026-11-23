// =============================================================================
// Camera.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Camera.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Camera.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/ICameraSubject.h"
#include "util/Math.h"
#include "util/Object.h"

namespace RBX
{
	static Reflection::EnumPropDescriptor<Camera, Camera::CameraType> desc_cameraType(
		"CameraType",
		"Camera",
		&Camera::getCameraType,
		&Camera::setCameraType,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Camera, G3D::CoordinateFrame> desc_CoordFrame(
		"CoordinateFrame",
		"Data",
		&Camera::getCameraCoordinateFrame,
		&Camera::setCameraCoordinateFrameNoLerp,
		Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Camera, G3D::CoordinateFrame> desc_Focus(
		"Focus",
		"Data",
		&Camera::getCameraFocus,
		&Camera::setCameraFocus,
		Reflection::PropertyDescriptor::STREAMING);
	static Reflection::RefPropDescriptor<Camera, Instance> cameraSubjectProp(
		"CameraSubject",
		"Camera",
		&Camera::getCameraSubjectInstance,
		&Camera::setCameraSubject,
		Reflection::PropertyDescriptor::STANDARD);

	// No out-of-line copy in the binary (inlined at every call site).
	void Camera::tellCameraMoved()
	{
		if (ICameraOwner* owner = getCameraOwner())
			owner->cameraMoved();
	}

	void Camera::setGCameraCoordinateFrame(const G3D::CoordinateFrame& coord)
	{
		if (Math::legalCameraCoord(coord))
			gCamera.setCoordinateFrame(coord);
	}

	Instance* Camera::getCameraSubjectInstance() const
	{
		return cameraSubject.get();
	}

	bool Camera::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const Workspace*>(instance) != NULL;
	}

	bool Camera::canZoom(int in) const
	{
		if (in > 0)
			return goalToFocusDistance() > distanceMin();
		else
			return goalToFocusDistance() < distanceMax();
	}

	void Camera::lookAt(const G3D::Vector3& point)
	{
		cameraFocus.translation = point;
		cameraGoal.lookAt(point);
	}

	bool Camera::canTilt(int up) const
	{
		float elevation = Math::elevationAngle(cameraGoal.lookVector());
		if (up < 0)
			return elevation >= -1.5707964f;
		else
			return elevation <= 1.5707964f;
	}

	ICameraSubject* Camera::getCameraSubject() const
	{
		Instance* instance = getCameraSubjectInstance();
		if (instance)
		{
			ICameraSubject* subject = dynamic_cast<ICameraSubject*>(instance);
			return subject;
		}
		return NULL;
	}

	void Camera::autoMode()
	{
		if (animationType != AUTO)
		{
			animationType = AUTO;
			tellCameraMoved();
		}
	}

	void Camera::onWrapMouse(const G3D::Vector2& wrapMouseDelta)
	{
		tiltRadians(wrapMouseDelta.y * -0.0052359882f);
		panRadians(wrapMouseDelta.x * -0.0069813174f);
	}

	bool Camera::zoom(float in)
	{
		if (cameraType == CUSTOM_CAMERA)
		{
			ICameraSubject* cameraSubject = getCameraSubject();
			if (cameraSubject)
				return cameraSubject->zoom(in, cameraGoal, cameraFocus);
		}
		else if (getCameraSubjectInstance() &&
				 (cameraType == FOLLOW_CAMERA ||
				  cameraType == ATTACH_CAMERA ||
				  cameraType == TRACK_CAMERA))
		{
			return characterZoom(in);
		}
		else
		{
			return nonCharacterZoom(in);
		}
		return false;
	}

	void Camera::setCameraType(CameraType type)
	{
		if (cameraType != type)
		{
			cameraType = type;
			raisePropertyChanged(desc_cameraType);
			tellCameraMoved();
		}
	}

	void Camera::setCameraSubject(Instance* newSubject)
	{
		if (newSubject != getCameraSubjectInstance())
		{
			if (dynamic_cast<ICameraSubject*>(newSubject))
			{
				cameraSubject = shared_from(newSubject);
				raisePropertyChanged(cameraSubjectProp);
				tellCameraMoved();
			}
		}
	}

	void Camera::setCameraFocus(const G3D::CoordinateFrame& value)
	{
		if (value != cameraFocus)
		{
			cameraFocus = value;
			raisePropertyChanged(desc_Focus);
			tellCameraMoved();
		}
	}

	void Camera::zoomExtents(Extents extents, const G3D::Rect2D& viewPort, Camera::ZoomType zoomType)
	{
		G3D::CoordinateFrame currentCoord = gCamera.getCoordinateFrame();
		extents.expand(0.1f);

		if (zoomType != ZOOM_CHAR_PART_DRAG || cameraType == CUSTOM_CAMERA)
		{
			if (cameraType == FIXED_CAMERA)
			{
				G3D::Vector3 scaler = extents.center() - cameraFocus.translation;
				cameraFocus.translation += scaler;
				cameraGoal.translation += scaler;
			}

			float low;
			if (zoomType == ZOOM_OUT_ONLY || zoomType == ZOOM_CHAR_PART_DRAG)
				low = goalToFocusDistance();
			else
				low = distanceMin();

			float current = goalToFocusDistance();

			if (zoomType == ZOOM_CHAR_PART_DRAG)
				extents.scale(1.1f);

			if (G3D::isFinite(low) && G3D::isFinite(current) && G3D::isFinite(distanceMax()))
				tryZoomExtents(low, current, distanceMax(), extents, viewPort);

			cameraGoal = gCamera.getCoordinateFrame();
			setGCameraCoordinateFrame(currentCoord);
			tellCameraMoved();
		}
	}

	bool Camera::zoomExtents(const G3D::Rect2D& viewPort)
	{
		if (ICameraOwner* owner = getCameraOwner())
		{
			zoomExtents(owner->computeCameraOwnerExtents(), viewPort, ZOOM_IN_OR_OUT);
			return true;
		}
		return false;
	}
}

#include "util/Name.h"

namespace RBX
{

void __thiscall Camera::updateFocus(void)
{
	if (cameraSubject)
	{
		cameraFocus = dynamic_cast<ICameraSubject*>(cameraSubject.get())->getLocation();
	}
}

}

#include "v8datamodel/ICharacterSubject.h"

namespace RBX
{
bool Camera::isFirstPersonCamera() const
{
	ICameraSubject* subject = cameraSubject.get() ? dynamic_cast<ICameraSubject*>(cameraSubject.get()) : 0;
	ICharacterSubject* character = dynamic_cast<ICharacterSubject*>(subject);
	if (character) return character->getCursorCenterLocked();
	return false;
}
}

#include "G3D/g3dmath.h"
#include <math.h>
#pragma intrinsic(atan2)

namespace RBX
{
extern const float cameraRadiansToDegrees;
void Camera::panUnits(int steps) {
	G3D::Vector3 look = cameraGoal.lookVector();
	float heading = atan2(-look.z, -look.x);
	int current = G3D::iRound(heading * 1.2732394933700562f + steps);
	panRadians(heading - current * 0.7853981852531433f);
}

bool Camera::tiltUnits(int steps) {
	float elevation = Math::getElevation(cameraGoal.lookVector());
	int current = G3D::iRound(elevation * cameraRadiansToDegrees * 0.1f);
	return tiltRadians((current + steps) * 0.1745329350233078f - elevation);
}
}
