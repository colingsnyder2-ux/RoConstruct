// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callee is StringConverter<CoordinateFrame>::convertToValue; the disassembly passes one stack argument, a pointer to an 8-byte local built from arg1 and arg2. Declared as a plain cdecl helper.
extern "C" bool fn_0060a2f0(void* arg);

// INFERRED: unknown global (the tag stored on failure, likely a vtable).
extern "C" char g_00826be8;

// INFERRED: local struct for the target object. It has a tag dword at +0 and an 8-byte payload at +8.
struct Fn4d8760Obj {
    const void* tag;
    int pad;
    int v0;
    int v1;
};

struct Fn4d8760Pair {
    int a;
    int b;
};

extern "C" Fn4d8760Obj* __fastcall fn_004d8760(Fn4d8760Obj* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    Fn4d8760Pair tmp;
    tmp.a = arg1;
    tmp.b = arg2;
    self->tag = 0;
    if (!fn_0060a2f0(&tmp)) {
        int* dst = &self->v0;
        if (dst) {
            dst[0] = tmp.a;
            dst[1] = tmp.b;
        }
        self->tag = &g_00826be8;
        return self;
    }
    self->tag = 0;
    return self;
}
