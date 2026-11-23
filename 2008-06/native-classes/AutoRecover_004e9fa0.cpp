// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object layout: [0]=vptr/flag, [8..0x18) = 16-byte payload. Callee takes only a pointer to the first stack args.
struct Fn4e9fa0Obj {
    const void* vptr;
    int pad4;
    int v[4];
};

// INFERRED: unknown global/vtable at the stored address
extern "C" char g_00826f5c[];

extern "C" int fn_0060a2f0(int* out);

extern "C" Fn4e9fa0Obj* __fastcall fn_004e9fa0(Fn4e9fa0Obj* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5)
{
    int buf[4];
    buf[0] = a1; buf[1] = a2; buf[2] = a3; buf[3] = a4;
    self->vptr = 0;
    if ((char)fn_0060a2f0(buf) != 0) {
        self->vptr = 0;
        return self;
    }
    int* p = self->v;
    if (p) {
        p[0] = buf[0];
        p[1] = buf[1];
        p[2] = buf[2];
        p[3] = buf[3];
    }
    self->vptr = g_00826f5c;
    return self;
}
