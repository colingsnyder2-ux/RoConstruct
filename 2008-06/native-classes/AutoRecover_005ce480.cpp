// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Camera.h"
#include "v8datamodel/ICameraOwner.h"

// INFERRED: Address denotes a Camera property descriptor.
extern char g_00979ab0;

extern "C" RBX::ICameraOwner* __fastcall fn_005cbf50(void* self, int unusedEdx);
extern "C" int __fastcall fn_005cdf70(void* self, int unusedEdx);

// INFERRED: Reconstructed from disassembly; byte match unverified.
extern "C" void __fastcall fn_005ce480(
    RBX::Camera* self, int unusedEdx,
    const G3D::CoordinateFrame& modelCoord, const G3D::Rect2D& viewPort)
{
    G3D::Vector3 look = modelCoord.lookVector();

    if (fabs(look.y) > 0.95)
        look = -G3D::Vector3::unitZ();
    else
    {
        look.y = 0;
        look = look.direction();
    }

    G3D::CoordinateFrame lookCoord;
    lookCoord.lookAt(look);
    lookCoord.rotation *= G3D::Matrix3::fromEulerAnglesZXY(
        G3D::toRadians(45), G3D::toRadians(35), 0.0f);

    look = lookCoord.lookVector();
    lookCoord.translation = look * 10.0f + modelCoord.translation;
    lookCoord.lookAt(modelCoord.translation);

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x1d4) != 0)
    {
        *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x1d4) = 0;
        self->raisePropertyChanged(
            *reinterpret_cast<RBX::Reflection::PropertyDescriptor*>(&g_00979ab0));
        if (RBX::ICameraOwner* owner = fn_005cbf50(self, 0))
            owner->cameraMoved();
    }

    self->setCameraFocus(modelCoord.translation);
    *reinterpret_cast<G3D::CoordinateFrame*>(
        reinterpret_cast<char*>(self) + 0x174) = lookCoord;
    fn_005cdf70(self, 0);

    if (RBX::ICameraOwner* owner = fn_005cbf50(self, 0))
        self->zoomExtents(owner->computeCameraOwnerExtents(), viewPort,
                          RBX::Camera::ZOOM_IN_OR_OUT);

    fn_005cdf70(self, 0);
}
