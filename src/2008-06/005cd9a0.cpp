// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_435aad3f0f5b5fb5.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#undef _RELEASEASSERT
#include "v8datamodel/Camera.h"
#include "util/Math.h"
namespace RBX {
Camera::Camera()
		: Base(),
		  cameraFocus(G3D::Vector3(0, 0, -5)),
		  cameraType(FIXED_CAMERA),
		  animationType(AUTO),
		  cameraExternallyAdjusted(false)
	{
		setName("Camera");
		gCamera.setNearPlaneZ(-1.25);
		gCamera.setFarPlaneZ(-5000);
		gCamera.setFieldOfView(G3D::toRadians(60));

		G3D::CoordinateFrame cameraCoord(G3D::Vector3(0, 5, 5));
		cameraCoord.lookAt(G3D::Vector3::zero());

		setGCameraCoordinateFrame(cameraCoord);
	}
void Camera::setGCameraCoordinateFrame(const G3D::CoordinateFrame& coord)
	{
		if (Math::legalCameraCoord(coord))
		{
			gCamera.setCoordinateFrame(coord);
		}
		else
		{
			RBXASSERT(false);
		}
	}
}
