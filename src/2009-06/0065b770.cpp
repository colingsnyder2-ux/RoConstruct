// from server: 100% by EspClaude
// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_espclaude_9a293c568f3c9565.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#include "v8datamodel/Camera.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/Math.h"
namespace RBX {
	static Reflection::EnumPropDescriptor<Camera, Camera::CameraType> desc_cameraType("CameraType", "Camera", &Camera::getCameraType, &Camera::setCameraType, Reflection::PropertyDescriptor::STANDARD); 
void Camera::tellCameraMoved() {
 if (ICameraOwner* owner = getCameraOwner()) owner->cameraMoved();
}
void Camera::setCameraType(CameraType type)
	{
		if ((*reinterpret_cast<CameraType*>(reinterpret_cast<char*>(this) + 0x13c)) != type)
		{
			(*reinterpret_cast<CameraType*>(reinterpret_cast<char*>(this) + 0x13c)) = type;
			raisePropertyChanged(desc_cameraType);
		}
	}
void Camera::setCameraCoordinateFrameNoLerp(const G3D::CoordinateFrame& value)
	{
		(*reinterpret_cast<G3D::CoordinateFrame*>(reinterpret_cast<char*>(this) + 0xdc)) = value;
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
}


