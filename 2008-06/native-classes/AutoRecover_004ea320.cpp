// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: callee is RBX::StringConverter<G3D::CoordinateFrame>::convertToValue(const std::string&, ...);
// only one stack arg (pointer to an 8-byte local) is pushed, so it is declared as a plain cdecl helper.
extern "C" char fn_0060a2f0(const void* src);

// INFERRED: unknown global at the old address 0x826f74 (likely a vtable / type descriptor).
extern "C" char g_00826f74;

// INFERRED: layout of the object being initialised; field meanings are unknown.
struct Pair8 {
    int a;
    int b;
};

struct Result8 {
    const void* tag;    // [esi]
    int pad;            // [esi+4]
    Pair8 data;         // [esi+8]
};

extern "C" Result8* __fastcall fn_004ea320(Result8* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    Pair8 local;
    local.a = arg1;
    local.b = arg2;
    self->tag = 0;
    if (!fn_0060a2f0(&local)) {
        // placement-new style construction (null check preserved)
        new (&self->data) Pair8(local);
        self->tag = &g_00826f74; // INFERRED: type/vtable pointer
        return self;
    }
    self->tag = 0;
    return self;
}
