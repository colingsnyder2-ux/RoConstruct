// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the symbol names in the disassembly comments do not match what the
// callees do (address collisions), so every callee is declared by address.
// The class layout is guessed from raw offsets.

extern "C" {
void* __fastcall fn_0071f210(void* self, int unusedEdx);
void* __fastcall fn_004e8160(void* self, int unusedEdx, float a1);
void* __fastcall fn_004f0810(void* self, int unusedEdx);
void* __fastcall fn_004782d0(void* self, int unusedEdx);
void* __fastcall fn_00514390(void* self, int unusedEdx);
void* __fastcall fn_00489470(void* self, int unusedEdx);
void* __fastcall fn_00481520(void* self, int unusedEdx);
int __fastcall fn_005527f0(void* self, int unusedEdx);
int __fastcall fn_00540560(void* self, int unusedEdx);
void* __fastcall fn_004d7560(void* self, int unusedEdx, void* other);
void __fastcall fn_00502a70(void* self, int unusedEdx);
void* fn_00551730();
int __fastcall fn_004dc4e0(void* self, int unusedEdx, int a1);

// INFERRED: unknown globals, named by address
extern unsigned char g_009738a0;
extern int g_00972894;
extern int g_0097288c;
// INFERRED: vtable of the derived class (unknown), named by address
extern void* g_0082d258[];
}

typedef int (__fastcall *VFn0)(void* self, int unusedEdx);
typedef void* (__fastcall *VFn1)(void* self, int unusedEdx, void* out);

static inline void** vtbl(void* o)
{
    return *(void***)o;
}

extern "C" void* __fastcall fn_00551f30(void* self, int unusedEdx, void* arg1)
{
    char* p = (char*)self;

    void* src = fn_0071f210(arg1, 0);
    fn_004e8160(self, 0, *(float*)((char*)src + 0x18));

    // INFERRED: derived-class vtable
    *(void***)self = g_0082d258;

    fn_004f0810(p + 0x28, 0);
    fn_004f0810(p + 0x2c, 0);
    fn_004782d0(p + 0x30, 0);

    void* o = fn_0071f210(arg1, 0);
    p[0x60] = (char)((VFn0)vtbl(o)[3])(o, 0);

    o = fn_0071f210(arg1, 0);
    p[0x61] = (char)((VFn0)vtbl(o)[4])(o, 0);

    fn_00514390(p + 0x68, 0);
    fn_00489470(p + 0xb8, 0);
    fn_00481520(p + 0xd8, 0);
    fn_005527f0(p + 0xe4, 0);
    fn_00540560(p + 0xf0, 0);

    if (g_009738a0 == 0) {
        void* o2 = fn_0071f210(arg1, 0);
        void* tmp = 0;
        void* r = ((VFn1)vtbl(o2)[5])(o2, 0, &tmp);
        void* held = r;
        fn_004d7560(p + 0x28, 0, held);
        fn_00502a70(&tmp, 0);
    }

    g_00972894 = g_00972894 + 1;
    g_0097288c = g_0097288c - 1;

    if (g_009738a0 != 0) {
        void* mat = fn_00551730();
        fn_004dc4e0(p + 0x28, 0, (int)mat);
        void* o3 = fn_0071f210(p + 0x28, 0);
        ((VFn0)vtbl(o3)[3])(o3, 0);
    }

    return self;
}
