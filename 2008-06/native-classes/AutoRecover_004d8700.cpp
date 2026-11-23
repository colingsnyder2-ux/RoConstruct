// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target's class and its layout are unknown. The object is modelled as a
// vtable-like dword at +0, an unused dword at +4, and an 8-byte payload at +8.
struct Fn4d8700Obj {
    const void* vtbl;   // +0
    int pad;            // +4
    int payload[2];     // +8
};

// StringConverter<G3D::CoordinateFrame>::convertToValue, called with one pointer argument.
// INFERRED: the pointer is to an 8-byte local built from arg1 and arg2.
extern "C" char __cdecl fn_0060a2f0(int* in);

// INFERRED: the value stored at [esi] on the failure path is the address of an unknown
// global (likely a vtable or type-descriptor object).
extern "C" char g_00826be0;

extern "C" Fn4d8700Obj* __fastcall fn_004d8700(Fn4d8700Obj* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    int local[2];
    local[0] = arg1;
    local[1] = arg2;
    self->vtbl = 0;
    if (!fn_0060a2f0(local)) {
        int* dst = self->payload;
        if (dst) {
            dst[0] = local[0];
            dst[1] = local[1];
        }
        self->vtbl = &g_00826be0;
        return self;
    }
    self->vtbl = 0;
    return self;
}
