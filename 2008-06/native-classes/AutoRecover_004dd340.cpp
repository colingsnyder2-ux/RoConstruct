// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: no class header was available, so Level is declared minimally here.
// INFERRED: fn_005489b0 is entered with the object in ecx and no stack argument, so
// it is declared __fastcall (object first, dummy edx) instead of cdecl; it is the dtor body.
// INFERRED: the deleting destructor is compiler-generated; an out-of-line constructor
// forces emission of the vtable (and thus the deleting destructor) without adding
// global initializer / atexit code.

namespace RBX {
namespace RenderBase {

struct Mesh {
    struct Level;
};

}
}

extern "C" void __fastcall fn_005489b0(RBX::RenderBase::Mesh::Level* self);

namespace RBX {
namespace RenderBase {

struct Mesh::Level {
    Level();
    virtual ~Level()
    {
        fn_005489b0(this);
    }
};

// INFERRED: constructor defined here only to force vtable / deleting dtor emission.
Mesh::Level::Level() {}

}
}
