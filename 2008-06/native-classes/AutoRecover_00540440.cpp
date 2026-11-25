// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were provided, so the object is treated as an opaque
// pointer. It is a deleting-less destructor body for a class deriving from
// G3D::ReferenceCountedObject (primary base at +0) and RBX::IRenderable (at +0xc).
// INFERRED: fn_005405d0 is called with no stack args, unlike the 6-arg declaration
// given; the disassembly pushes nothing before the call.
extern "C" void __fastcall fn_005405d0(void* self, int unusedEdx);
// RBX::IRenderable::~IRenderable
extern "C" void __fastcall fn_0047d410(void* self, int unusedEdx);
// G3D::ReferenceCountedObject::~ReferenceCountedObject
extern "C" void __fastcall fn_007accf0(void* self, int unusedEdx);

extern "C" void __fastcall fn_00540440(void* self, int unusedEdx)
{
    // INFERRED: the SEH/unwind state machine (1 -> 0 -> -1) from the original
    // is produced by the compiler from the nested destructor sequence; the
    // /EHsc frame itself is not reproduced explicitly here.
    char* p = static_cast<char*>(self);
    fn_005405d0(p + 0xc, 0);
    fn_0047d410(p + 0xc, 0);
    fn_007accf0(self, 0);
}
