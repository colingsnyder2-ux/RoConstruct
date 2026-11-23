// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available, so minimal G3D/RBX declarations are
// local to this file. Member offsets come from the disassembly.
namespace G3D {
class Vector3 {
public:
    float x, y, z;
};
class Matrix3 {
public:
    float e[9];
    Vector3 getColumn(int c) const;
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
};
}

namespace RBX {
class Math {
public:
    static void setHeadingElevation(G3D::CoordinateFrame& cf, float heading, float elevation);
};
}

// INFERRED: layout of the camera-like object, with fields at the offsets used by the code.
struct CamObj {
    char pad0[0x174];
    G3D::CoordinateFrame cframe;   // 0x174
    G3D::Matrix3 rotCopy;          // 0x1a4
    G3D::Vector3 focus;            // 0x1c8
    char pad1[0x1e4 - 0x1d4];
    bool dirty;                    // 0x1e4
};

// INFERRED: the constant at 0x828b60 is the distance from the focus to the camera.
// Its value is unknown, so it is passed in as an extern.
extern const float kCamDistance_00828b60;

extern "C" void __fastcall fn_005cc690(CamObj* self, int unusedEdx, float heading, float elevation, float unused)
{
    RBX::Math::setHeadingElevation(self->cframe, heading, elevation);
    self->rotCopy = self->cframe.rotation;

    float dist = kCamDistance_00828b60;
    G3D::Vector3 col = self->cframe.rotation.getColumn(2);

    self->cframe.translation.x = self->focus.x - col.x * dist;
    self->cframe.translation.y = self->focus.y - col.y * dist;
    self->cframe.translation.z = self->focus.z - col.z * dist;
    self->dirty = true;
}
