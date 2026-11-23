// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers available for these classes; the types below are local stand-ins and the callees use the fn_ convention.
struct V3 { float x, y, z; };
struct V2 { float x, y; };

struct RC {
    void** vtbl;
    long refs;
};

extern "C" {
    __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
    extern char vtbl_00827184[];
    void __fastcall fn_00548570(void* self, int unusedEdx);
    int fn_006a0920(int a1);
    void __fastcall fn_004dd2e0(void* self, int unusedEdx, int prim);
    void __fastcall fn_004dcbb0(void* arr, int unusedEdx, RC** p);
    void __fastcall fn_004fd430(void* self, int unusedEdx, RC** level, V3 size, int a, int b);
    V3* fn_005ec9d0(V3* out, const V3* in, int face, RC** level);
    const V2* __fastcall fn_005185d0(const V3* self, int unusedEdx);
    void __fastcall fn_00500ca0(void* builder, int unusedEdx, int face, int purpose);
    void __fastcall fn_0045ad90(RC* self, int unusedEdx);
}
extern "C" const float g_const_0081c434;

static void release(RC* p)
{
    if (p && InterlockedDecrement(&p->refs) == 0) {
        fn_0045ad90(p, 0);
        if (p)
            ((void* (__thiscall*)(RC*, int))p->vtbl[0])(p, 1);
    }
}

extern "C" void* __fastcall fn_004fd960(char* self, int unusedEdx, const V3* size, int face, const V2* scale)
{
    fn_00548570(self, 0);
    *(void**)self = vtbl_00827184;
    *(int*)(self + 0x84) = 3;

    RC* level = (RC*)fn_006a0920(0x28);
    if (level)
        fn_004dd2e0(level, 0, 5);

    RC* ref = 0;
    if (level) {
        ref = level;
        InterlockedIncrement(&level->refs);
    }
    fn_004dcbb0(self + 0xc, 0, &ref);

    char builder[0x10];
    V3 sz = *size;
    fn_004fd430(builder, 0, (RC**)&level, sz, 0, 0xc);

    V3 uvw;
    fn_005ec9d0(&uvw, size, face, (RC**)&level);
    const V2* o = fn_005185d0(&uvw, 0);
    float c = g_const_0081c434;
    float u = (o->x * c) / scale->x;
    float v = (c * o->y) / scale->y;
    *(float*)(builder + 0x18) = u; // INFERRED: builder uv scale slots
    *(float*)(builder + 0x1c) = v;
    fn_00500ca0(builder, 0, face, 1);

    release(*(RC**)(builder + 0xc)); // INFERRED: builder-held level ref
    release(ref);
    return self;
}
