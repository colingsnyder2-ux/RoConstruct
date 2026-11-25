// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /U_RELEASEASSERT
#include "v8datamodel/Camera.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ICharacterSubject.h"
#include "util/Math.h"

// INFERRED: Address denotes a Camera property descriptor (desc_cameraType).
extern char g_00979ab0;

extern "C" RBX::ICameraOwner* __fastcall fn_005cbf50(void* self);
extern "C" int __fastcall fn_005cdf70(void* self);

static inline G3D::Vector3 helper_lookVector(const G3D::CoordinateFrame& cf)
{
    return cf.rotation.getColumn(2) * G3D::CoordinateFrame::zLookDirection;
}

static inline void helper_setCameraType(RBX::Camera* self, RBX::Camera::CameraType type)
{
    int& cameraType = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x1d4);
    if (cameraType != static_cast<int>(type))
    {
        cameraType = static_cast<int>(type);
        self->raisePropertyChanged(
            *reinterpret_cast<RBX::Reflection::PropertyDescriptor*>(&g_00979ab0));
        if (RBX::ICameraOwner* owner = fn_005cbf50(self))
            owner->cameraMoved();
    }
}

static inline void helper_setCameraCoordinateFrameNoLerp(RBX::Camera* self, const G3D::CoordinateFrame& value)
{
    *reinterpret_cast<G3D::CoordinateFrame*>(reinterpret_cast<char*>(self) + 0x174) = value;
    fn_005cdf70(self);
}

static inline bool helper_zoomExtents(RBX::Camera* self, const G3D::Rect2D& viewPort)
{
    if (RBX::ICameraOwner* owner = fn_005cbf50(self))
    {
        self->zoomExtents(owner->computeCameraOwnerExtents(), viewPort, RBX::Camera::ZOOM_IN_OR_OUT);
        return true;
    }
    return false;
}

// INFERRED: Camera::setImageServerViewNoLerp (005ce480), matching Camera.cpp.
// Uses static inline helper_lookVector (rotation.getColumn(2) * zLookDirection) to avoid emitting lookVector COMDAT.
extern "C" void __fastcall fn_005ce480(
    RBX::Camera* self, int unusedEdx,
    const G3D::CoordinateFrame& modelCoord, const G3D::Rect2D& viewPort)
{
    G3D::Vector3 look = helper_lookVector(modelCoord);

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

    look = helper_lookVector(lookCoord);
    lookCoord.translation = (look * 10.0f) + modelCoord.translation;

    lookCoord.lookAt(modelCoord.translation);

    helper_setCameraType(self, RBX::Camera::FIXED_CAMERA);
    self->setCameraFocus(modelCoord.translation);
    helper_setCameraCoordinateFrameNoLerp(self, lookCoord);
    helper_zoomExtents(self, viewPort);
    fn_005cdf70(self);
}
