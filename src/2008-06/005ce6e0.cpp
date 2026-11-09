// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_camera_fly_native_family_5dba1c85aa68a635.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/Camera.h", "../roc_camera_fly_native_header_f804c210c099df00.cpp")
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

namespace RBX {

	void Camera::setCameraCoordinateFrameNoLerp(const G3D::CoordinateFrame& value)
	{
		(*(G3D::CoordinateFrame*)((char*)this+0x174)) = value;
		goalToCamera();
	}

	void Camera::setImageServerViewNoLerp(const G3D::CoordinateFrame& modelCoord, const G3D::Rect2D& viewPort)
	{
		G3D::Vector3 look = modelCoord.lookVector();

		bool noTilt = (fabs(look.y) > 0.95);
		if (noTilt)
		{
			look = -G3D::Vector3::unitZ();
		}
		else
		{
			look.y = 0;
			look = look.direction();
		}

		G3D::CoordinateFrame lookCoord;

		lookCoord.lookAt(look);
		lookCoord.rotation *= G3D::Matrix3::fromEulerAnglesZXY(G3D::toRadians(45), G3D::toRadians(35), 0.0f);

		look = lookCoord.lookVector();
		lookCoord.translation = (look * 10.0f) + modelCoord.translation;

		lookCoord.lookAt(modelCoord.translation);

		setCameraType(FIXED_CAMERA);
		setCameraFocus(modelCoord.translation);
		setCameraCoordinateFrameNoLerp(lookCoord);
		zoomExtents(viewPort);
		goalToCamera();
	}

	float Camera::getNewZoomDistance(float currentDistance, float in)
	{
		float const ZOOM_FACTOR = 0.25f;

		if (in > 0.0f)
		{
			currentDistance = G3D::max<float>(currentDistance / (1.0 + in * ZOOM_FACTOR), distanceMin());
		} 	
		else if (in < 0.0f)
		{
			return G3D::min<float>(currentDistance * (1.0 - in * ZOOM_FACTOR), distanceMax());
		}

		return currentDistance;
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

namespace RBX {
class NavKeys
{
public:
	bool forward_arrow;  // 0x00
	bool backward_arrow; // 0x01
	bool left_arrow;     // 0x02
	bool right_arrow;    // 0x03
	bool forward_asdw;   // 0x04
	bool backward_asdw;  // 0x05
	bool left_asdw;      // 0x06
	bool right_asdw;     // 0x07
	bool space;          // 0x08
		bool forward() const		{return (forward_arrow || forward_asdw);}

		bool backward() const		{return (backward_arrow || backward_asdw);}

		bool left() const			{return (left_arrow || left_asdw);}
		
		bool right() const			{return (right_arrow || right_asdw);}

		bool arrowKeyDown() const	{return (forward_arrow || backward_arrow || left_arrow || right_arrow);}

		bool asdwKeyDown() const	{return (forward_asdw || backward_asdw || left_asdw || right_asdw);}


 bool navKeyDown() const {return arrowKeyDown() || asdwKeyDown() || space;}
};


	static Reflection::EnumPropDescriptor<Camera, Camera::CameraType> desc_cameraType("CameraType", "Camera", &Camera::getCameraType, &Camera::setCameraType, Reflection::PropertyDescriptor::STANDARD); 

	void Camera::setCameraType(CameraType type)
	{
		if ((*(CameraType*)((char*)this+0x1d4)) != type)
		{
			(*(CameraType*)((char*)this+0x1d4)) = type;
			raisePropertyChanged(desc_cameraType);

			tellCameraMoved();
		}
	}

void Camera::doFly(const NavKeys& nav, int steps)
{
 if (nav.navKeyDown()) {
  float accelerationMultiplier = 2.0f;
  if (steps > 120) accelerationMultiplier = 8.0f;
  else if (steps > 60) accelerationMultiplier = 4.0f;
  G3D::CoordinateFrame current = getCameraCoordinateFrame();
  G3D::Vector3 look = current.lookVector();
  G3D::Vector3 right = current.rightVector();
  G3D::Vector3 delta;
  if (nav.forward()) delta += look * accelerationMultiplier;
  if (nav.backward()) delta -= look * accelerationMultiplier;
  if (nav.right()) delta += right * accelerationMultiplier;
  if (nav.left()) delta -= right * accelerationMultiplier;
  current.translation += delta;
  setCameraType(Camera::FIXED_CAMERA);
  setCameraCoordinateFrameNoLerp(current);
  setCameraFocus(current.translation + 20.0f * look);
 }
}

}
