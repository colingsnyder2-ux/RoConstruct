// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: no class header was provided, so Vector3 is declared locally.
// The declaration is out-of-line so the call binds to ??0Vector3@G3D@@QAE@XZ.
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3();
};
}

// INFERRED: the owning class is unknown. It holds a Vector3 at offset 0 and a
// sub-object at offset 0xc, whose initializer is fn_00540560.
struct Obj552fa0 {
    G3D::Vector3 v;      // offset 0
    char sub[1];         // offset 0xc (INFERRED: opaque member)
};

extern "C" int __fastcall fn_00540560(void* self, int unusedEdx);

extern "C" Obj552fa0* __fastcall fn_00552fa0(Obj552fa0* self, int unusedEdx)
{
    new (&self->v) G3D::Vector3();
    fn_00540560(reinterpret_cast<char*>(self) + 0xc, 0);
    return self;
}
