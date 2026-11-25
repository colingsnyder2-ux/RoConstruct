// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: argument roles and the vtable store are guesses. The 9-dword signature
// comes from the disassembly (ret 0x24). The bytes are not verified against the target.

extern "C" int* __fastcall fn_005d2280(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" void* fn_005d2760(int a, int b);
extern "C" void* __fastcall fn_0048b180(void* self, int unusedEdx, void* classDesc);
extern "C" char g_0083bd70[];

// INFERRED: owning pointer released into a local that is deleted on scope exit
struct Local_005d2990 {
    int* p;
    ~Local_005d2990() { if (p) operator delete(p); }
};

extern "C" void* __fastcall fn_005d2990(void* self, int unusedEdx,
    int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    Local_005d2990 owned;
    int* r = fn_005d2280(self, 0, a9, a6, a7, a8, a3, a4, a5);
    int* taken = (int*)*r;
    *r = 0;
    owned.p = taken;
    void* cd = fn_005d2760(a1, a2);
    fn_0048b180(self, 0, cd);
    // owned destructs here: delete of the owned pointer if non-null
    *(void**)self = (void*)g_0083bd70;
    return self;
}
