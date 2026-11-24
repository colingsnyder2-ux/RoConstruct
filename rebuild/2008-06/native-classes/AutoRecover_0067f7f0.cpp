// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: Ogre headers not locatable by include path; minimal dllimport declarations
// give the same import symbol ?setBackgroundColour@Viewport@Ogre@@QAEXABVColourValue@2@@Z.
namespace Ogre {
class ColourValue {
public:
    float r, g, b, a;
    ColourValue(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};
class __declspec(dllimport) Viewport {
public:
    void setBackgroundColour(const ColourValue& colour);
};
}

// INFERRED: arg types are opaque; only the offsets used by the disassembly are modelled.
struct FnColorSrc { char pad[0xc]; float r, g, b; };
struct FnViewTarget { char pad[0x10]; Ogre::Viewport* viewport; };
struct FnSelf { char pad[0xb8]; char enabled; };

extern "C" int __fastcall fn_0067f230(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_0067f550(void* self, int unusedEdx, int a1, int a2);

extern "C" void __fastcall fn_0067f7f0(FnSelf* self, int unusedEdx, FnViewTarget* target, FnColorSrc* src)
{
    Ogre::ColourValue c(src->r, src->g, src->b, 1.0f);
    target->viewport->setBackgroundColour(c);
    if (self->enabled) {
        fn_0067f230(self, 0, (int)target, (int)src);
        fn_0067f550(self, 0, (int)target, (int)src);
    }
}
