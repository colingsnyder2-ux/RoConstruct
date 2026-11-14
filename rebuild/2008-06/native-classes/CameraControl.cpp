// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/camera-zoom
// RBX::Camera control methods (unit RBX::Camera, 005cbf20-005ce430). Layout from the binary (lookAt 005cc010,
// zoom 005cce80, setCameraSubject 005cde10): gCamera +0x130, cameraGoal +0x174, cameraFocus +0x1a4,
// cameraType +0x1d4, animationType +0x1d8, cameraSubject +0x1dc (shared_count +0x1e0).
// Callees kept out of line in the original: getCameraOwner 005cbf50, getNewZoomDistance 005cc240,
// nonCharacterZoom 005cc480, characterZoom 005cc560, tiltRadians 005cc740, panRadians 005cc810,
// tryZoomExtents 005cdff0. tellCameraMoved / setGCameraCoordinateFrame have no out-of-line copy in the binary:
// every caller inlines them (getCameraOwner + vtable slot 0xc; legalCameraCoord 005dd9b0 + GCamera 005107e0).
#include "v8datamodel/Camera.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/ICameraSubject.h"
#include "util/Math.h"
#include "util/Object.h"

namespace RBX
{
	// Raised by setCameraType 005cddd0 (00979ab0), setCameraSubject 005cde10 (00979a90), setCameraFocus 005cdf00
	// (00979a74). Taking &getCameraCoordinateFrame here is what emits the in-class body 0045af00.
	static Reflection::EnumPropDescriptor<Camera, Camera::CameraType> desc_cameraType("CameraType", "Camera", &Camera::getCameraType, &Camera::setCameraType, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Camera, G3D::CoordinateFrame> desc_CoordFrame("CoordinateFrame", "Data", &Camera::getCameraCoordinateFrame, &Camera::setCameraCoordinateFrameNoLerp, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Camera, G3D::CoordinateFrame> desc_Focus("Focus", "Data", &Camera::getCameraFocus, &Camera::setCameraFocus, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::RefPropDescriptor<Camera, Instance> cameraSubjectProp("CameraSubject", "Camera", &Camera::getCameraSubjectInstance, &Camera::setCameraSubject, Reflection::PropertyDescriptor::STANDARD);

	// No out-of-line copy in the binary (inlined at every call site).
	void Camera::tellCameraMoved()
	{
		if (ICameraOwner* owner = getCameraOwner())
			owner->cameraMoved();
	}

	// No out-of-line copy in the binary (inlined into zoomExtents 005ce0d0).
	void Camera::setGCameraCoordinateFrame(const G3D::CoordinateFrame& coord)
	{
		if (Math::legalCameraCoord(coord))
			gCamera.setCoordinateFrame(coord);
	}

	// Out-of-line copy needed by cameraSubjectProp; inlined by getCameraSubject 005cc420, zoom 005cce80 and
	// setCameraSubject 005cde10 (mov eax, [ecx+0x1dc]).
	Instance* Camera::getCameraSubjectInstance() const
	{
		return cameraSubject.get();
	}

	// 005cbf20 ?askSetParent@Camera@RBX@@EBE_NPBVInstance@2@@Z
	bool Camera::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const Workspace*>(instance) != NULL;
	}

	// 005cbf90 ?canZoom@Camera@RBX@@QBE_NH@Z
	bool Camera::canZoom(int in) const
	{
		if (in > 0)
			return goalToFocusDistance() > distanceMin();
		else
			return goalToFocusDistance() < distanceMax();
	}

	// 005cc010 ?lookAt@Camera@RBX@@QAEXABVVector3@G3D@@@Z
	void Camera::lookAt(const G3D::Vector3& point)
	{
		cameraFocus.translation = point;
		cameraGoal.lookAt(point);
	}

	// 005cc040 ?canTilt@Camera@RBX@@QBE_NH@Z (elevationAngle 005de190; limits -/+pi/2 0081e370 / 0081e374)
	bool Camera::canTilt(int up) const
	{
		float elevation = Math::elevationAngle(cameraGoal.lookVector());
		if (up < 0)
			return elevation >= -1.5707964f;
		else
			return elevation <= 1.5707964f;
	}

	// 005cc420 ?getCameraSubject@Camera@RBX@@QBEPAVICameraSubject@2@XZ
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

	// 005cc450 ?autoMode@Camera@RBX@@QAEXXZ
	void Camera::autoMode()
	{
		if (animationType != AUTO)
		{
			animationType = AUTO;
			tellCameraMoved();
		}
	}

	// 005cce40 ?onWrapMouse@Camera@RBX@@QAEXABVVector2@G3D@@@Z (factors 0083a448 / 0083a444)
	void Camera::onWrapMouse(const G3D::Vector2& wrapMouseDelta)
	{
		tiltRadians(wrapMouseDelta.y * -0.0052359882f);
		panRadians(wrapMouseDelta.x * -0.0069813174f);
	}

	// 005cce80 ?zoom@Camera@RBX@@QAE_NM@Z (ICameraSubject::zoom is vtable slot 0x10)
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

	// 005cddd0 ?setCameraType@Camera@RBX@@QAEXW4CameraType@12@@Z
	void Camera::setCameraType(CameraType type)
	{
		if (cameraType != type)
		{
			cameraType = type;
			raisePropertyChanged(desc_cameraType);
			tellCameraMoved();
		}
	}

	// 005cde10 ?setCameraSubject@Camera@RBX@@QAEXPAVInstance@2@@Z (shared_from 00618a40)
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

	// 005cdf00 ?setCameraFocus@Camera@RBX@@QAEXABVCoordinateFrame@G3D@@@Z (CoordinateFrame::operator!= 004765e0)
	void Camera::setCameraFocus(const G3D::CoordinateFrame& value)
	{
		if (value != cameraFocus)
		{
			cameraFocus = value;
			raisePropertyChanged(desc_Focus);
			tellCameraMoved();
		}
	}

	// 005ce0d0 ?zoomExtents@Camera@RBX@@QAEXVExtents@2@ABVRect2D@G3D@@W4ZoomType@12@@Z
	// (expand 0.1f 0081e704, scale 1.1f 0083a6e4, G3D::isFinite 004a5940)
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

	// 005ce400 ?zoomExtents@Camera@RBX@@QAE_NABVRect2D@G3D@@@Z (computeCameraOwnerExtents is vtable slot 0x10)
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
