// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

namespace G3D { class Color3; }

namespace RBX
{
    // INFERRED: a virtual base makes PartInstance pointer-to-members 12 bytes
    // {code, this-adjust, vbtable index}, matching the three-dword argument blocks.
    class PartInstanceVBase {};

    class PartInstance : public virtual PartInstanceVBase
    {
    public:
        // INFERRED: getter at 0x00598bf0, setter at 0x0059e3d0
        const G3D::Color3& getColor() const;
        void setColor(const G3D::Color3& c);
    };
}

typedef const G3D::Color3& (RBX::PartInstance::*ColorGetter)() const;
typedef void (RBX::PartInstance::*ColorSetter)(const G3D::Color3&);

// PropDescriptor<PartInstance,Color3> constructor (thiscall)
extern "C" int __fastcall fn_0059ca00(void* self, int unusedEdx,
                                      const char* name, const char* category,
                                      ColorGetter getter, ColorSetter setter,
                                      int flags);

// INFERRED: the static prop_Color object lives at 0x0097610c
extern "C" char g_0097610c[];

// INFERRED: atexit destructor stub for prop_Color
extern "C" void fn_007fde10(void);

// INFERRED: the mangled dynamic-initializer name cannot be written in C++; using fn_<addr> convention
extern "C" void fn_007f4630(void)
{
    fn_0059ca00(g_0097610c, 0,
                "Color", "Appearance",
                &RBX::PartInstance::getColor, &RBX::PartInstance::setColor,
                0);
    atexit(fn_007fde10);
}
