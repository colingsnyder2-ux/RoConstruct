// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local declarations; the native headers are not included
// because the previous include path did not exist. Mangled names match the
// disassembly comments.
namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2() {}
};
class Vector3 {
public:
    float x, y, z;
    Vector2 xz() const;
};
class CoordinateFrame {
public:
    float rotation[9];
    Vector3 translation;
};
}

namespace RBX {
class ModelInstance;
class PartInstance {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class Humanoid {
public:
    static PartInstance* getHeadFromCharacter(const ModelInstance* character);
};
}

// INFERRED: owner object type unknown; accessed by offset, as in the disassembly.
struct MapView;
struct MapScale;

extern "C" MapScale* fn_00492e00(MapView* self);
extern "C" void __fastcall fn_00489910(MapView* self, int unusedEdx, float* outRect);
extern "C" void __fastcall fn_0048b8a0(MapView* self, int unusedEdx, float* rect, const void* a, const void* b);
extern "C" void __fastcall fn_0048ae50(void* target, int unusedEdx, float* rect);

extern "C" const double kScaleLimitHi; // 0x00821e00 INFERRED name
extern "C" const double kScaleLimitLo; // 0x00821df8 INFERRED name
extern "C" const float kFloatOne;      // 0x00819bac INFERRED name
extern "C" const float kFloatBias;     // 0x0081c434 INFERRED name

// INFERRED: __thiscall, one stack arg (ret 4); the arg is the thiscall target of fn_0048ae50.
extern "C" void __fastcall fn_004930d0(MapView* self, int unusedEdx, void* target)
{
    char* base = reinterpret_cast<char*>(self);
    MapScale* scaleObj = fn_00492e00(self);
    RBX::ModelInstance* character = *reinterpret_cast<RBX::ModelInstance**>(base + 0x170);
    if (!scaleObj || !character)
        return;

    RBX::PartInstance* head = RBX::Humanoid::getHeadFromCharacter(character);
    if (!head)
        return;

    // INFERRED: out buffer layout from stack offsets (+0, +8, +0x10 read).
    float view[6];
    fn_00489910(self, 0, view);
    float w = view[2] - view[0];
    float h = view[4] - view[2];

    G3D::Vector2 pos = head->getCoordinateFrame().translation.xz();

    char* so = reinterpret_cast<char*>(scaleObj);
    double scale = (double)(1.0f / *reinterpret_cast<float*>(so + 0x1c0)) * *reinterpret_cast<double*>(so + 0x1c8);

    // INFERRED: clamp branches reconstructed from the x87 flow; exact operand order is a guess.
    float a, b;
    if (kScaleLimitHi > scale) {
        a = w * kFloatOne;
        b = h * kFloatOne;
    } else if (kScaleLimitLo > scale) {
        a = w;
        b = h;
    } else {
        a = w + kFloatBias;
        b = h + kFloatBias;
    }
    float fa = (float)scale * a;
    float fb = (float)scale * b;

    float rect[4];
    rect[0] = pos.x - fa;
    rect[1] = pos.y - fb;
    rect[2] = pos.x + fa;
    rect[3] = pos.y + fb;

    fn_0048b8a0(self, 0, rect, reinterpret_cast<const void*>(0x96fdd0), reinterpret_cast<const void*>(0x96fcf0));
    fn_0048ae50(target, 0, rect);
}
