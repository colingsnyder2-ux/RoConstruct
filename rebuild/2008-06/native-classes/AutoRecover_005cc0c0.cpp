// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <math.h>
namespace G3D { class CoordinateFrame; }
namespace RBX {
class Math {
public:
    static void getHeadingElevation(const G3D::CoordinateFrame& cf, float& heading, float& elevation);
};
}

// INFERRED: layout from offsets only; object type unknown.
struct CamLike {
    char pad0[0x174];
    char frame[0x24];   // CoordinateFrame at +0x174
    float pos[3];       // +0x198
    char pad1[0x1c8 - 0x1a4];
    float focus[3];     // +0x1c8
};

extern "C" void __fastcall fn_005cc0c0(CamLike* self, int unusedEdx, float* heading, float* elevation, float* outDistance)
{
    RBX::Math::getHeadingElevation(*(const G3D::CoordinateFrame*)self->frame, *heading, *elevation);
    float dx = self->pos[0] - self->focus[0];
    float dy = self->pos[1] - self->focus[1];
    float dz = self->pos[2] - self->focus[2];
    *outDistance = (float)sqrt((double)(dx * dx + dy * dy + dz * dz));
}
