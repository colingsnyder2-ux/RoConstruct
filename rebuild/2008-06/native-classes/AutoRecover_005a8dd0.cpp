// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct S {
    char pad0[0x10];
    char pad10[0x10];
    char pad20[0x10];
    char pad30[0x14];
    char pad44[0x20];
    char pad64[0x20];
    char pad84[0x20];
    char padA4[0x20];
    char padC4[4];
};

// INFERRED: Instance::Instance(const char*) is thiscall; modeled as stdcall with ecx (this) passed through.
extern "C" void __stdcall fn_0055b960(const char*);

// INFERRED: the unknown vtable-like globals are declared as opaque symbols.
extern "C" char g_008197fc[];
extern "C" char g_008197f0[];
extern "C" char g_008197e8[];
extern "C" char g_008197e0[];
extern "C" char g_008197d0[];
extern "C" char g_008197c0[];
extern "C" char g_008197b0[];
extern "C" char g_008197a0[];
extern "C" char g_00819790[];
extern "C" char g_00819780[];

extern "C" S* __fastcall fn_005a8dd0(S* self, int unusedEdx, const char* name) {
    fn_0055b960(name);
    *(void**)((char*)self + 0x00) = g_008197fc;
    *(void**)((char*)self + 0x10) = g_008197f0;
    *(void**)((char*)self + 0x14) = g_008197e8;
    *(void**)((char*)self + 0x20) = g_008197e0;
    *(void**)((char*)self + 0x24) = g_008197d0;
    *(void**)((char*)self + 0x44) = g_008197c0;
    *(void**)((char*)self + 0x64) = g_008197b0;
    *(void**)((char*)self + 0x84) = g_008197a0;
    *(void**)((char*)self + 0xa4) = g_00819790;
    *(void**)((char*)self + 0xc4) = g_00819780;
    return self;
}
