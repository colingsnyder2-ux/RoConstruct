// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/Camera.h"
#include "util/Math.h"

// INFERRED: Camera::setHeadingElevationDistance(float heading, float elevation, float distance).
// Members of RBX::Camera accessed by verified offset (+0x174 cameraGoal, +0x1a4 cameraFocus.rotation,
// +0x1c8 cameraFocus.translation, +0x1e4 cameraExternallyAdjusted).
extern "C" void __fastcall fn_005cc690(char* self, int unusedEdx, float heading, float elevation, float distance)
{
    RBX::Math::setHeadingElevation(*reinterpret_cast<G3D::CoordinateFrame*>(self + 0x174), heading, elevation);
    *reinterpret_cast<G3D::Matrix3*>(self + 0x1a4) = reinterpret_cast<G3D::CoordinateFrame*>(self + 0x174)->rotation;

    reinterpret_cast<G3D::CoordinateFrame*>(self + 0x174)->translation =
        *reinterpret_cast<G3D::Vector3*>(self + 0x1c8) -
        (reinterpret_cast<G3D::CoordinateFrame*>(self + 0x174)->rotation.getColumn(2) * G3D::CoordinateFrame::zLookDirection) * distance;
    *reinterpret_cast<bool*>(self + 0x1e4) = true;
}
