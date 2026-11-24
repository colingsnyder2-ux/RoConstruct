// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>

// INFERRED: String stands in for the 28-byte std::string; its destructor is the
// MSVCP90 import called through the pointer at 0x802468.
struct String;
typedef void (__thiscall *DestroyStringFunction)(String *);
extern DestroyStringFunction destroyString;

struct String
{
    char storage[28];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

namespace RBX {
namespace LDraw2Lua {
    // INFERRED: parameter is const char* (the callee is passed a string literal).
    String resolveMapPath(const char *);
}
}

// INFERRED: argument types chosen from the call sites (context, path string, flag).
extern "C" void *fn_00551920(void *a1, const String &a2, bool a3);
extern "C" void *fn_00551a30(void *a1, const String &a2);

struct Reference;

namespace G3D {
    class Texture;
    template <class T>
    class ReferenceCountedPointer
    {
    private:
        T *m_pointer;
        void setPointer(T *x);
        friend struct ::Reference;
    };
}

struct Reference
{
    G3D::ReferenceCountedPointer<G3D::Texture> ptr;
    Reference() { ptr.m_pointer = 0; }
    ~Reference();
    void operator=(void *p)
    {
        ptr.setPointer(static_cast<G3D::Texture *>(p));
    }
};

struct Material
{
    Reference strip;
    Reference surfaces;
    Reference john;
    Reference extra;

    __forceinline Material(void *context)
    {
        surfaces = fn_00551920(
            context, RBX::LDraw2Lua::resolveMapPath("textures\\surfaces.png"), true);
        john = fn_00551920(
            context, RBX::LDraw2Lua::resolveMapPath("textures\\JohnTex.png"), false);
        strip = fn_00551a30(
            context, RBX::LDraw2Lua::resolveMapPath("textures\\SurfacesStrip.png"));
    }
};

extern "C" Material * __fastcall fn_004f0920(Material *self, int unusedEdx, void *context)
{
    // INFERRED: explicit constructor call (MSVC extension) reproduces the in-place ctor body.
    self->Material::Material(context);
    return self;
}
