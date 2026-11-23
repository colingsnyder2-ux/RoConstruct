// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from disassembly only: vtable at +0, 8-byte payload at +8.
struct Obj004e9ee0 {
    void* vtbl;
    int pad;
    int v[2];
};

// INFERRED: unknown global at the vtable address stored into the object.
extern "C" char g_00826eb0;

// INFERRED: StringConverter<CoordinateFrame>::convertToValue; one stack arg, caller cleans.
extern "C" bool __cdecl fn_0060a2f0(void* out);

extern "C" Obj004e9ee0* __fastcall fn_004e9ee0(Obj004e9ee0* self, int unusedEdx, int a1, int a2, int a3)
{
    int tmp[2];
    tmp[0] = a1;
    tmp[1] = a3;
    self->vtbl = 0;
    if (!fn_0060a2f0(tmp)) {
        int* p = self->v;
        if (p) {
            p[0] = tmp[0];
            p[1] = tmp[1];
        }
        self->vtbl = &g_00826eb0;
        return self;
    }
    self->vtbl = 0;
    return self;
}
