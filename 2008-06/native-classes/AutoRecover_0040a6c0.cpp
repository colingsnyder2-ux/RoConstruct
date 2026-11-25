// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0080ba94[];
extern "C" char g_0080baa4[];
extern "C" char g_0080bab4[];
extern "C" char g_0080bac4[];
extern "C" char g_0080bad4[];
extern "C" char g_0080bae4[];
extern "C" char g_0080baf4[];
extern "C" char g_0080bafc[];
extern "C" char g_0080bb04[];
extern "C" char g_0080bb14[];

// INFERRED: object with vtable-like pointer slots at 0x00,0x10,0x14,0x20,0x24,0x44,0x64,0x84,0xa4,0xc4;
// file-local layout, matches the server-verified analog.
struct Local_0040a6c0 {
    char pad0[0x10];
    void* p10;
    void* p14;
    char pad18[0x8];
    void* p20;
    void* p24;
    char pad28[0x1c];
    void* p44;
    char pad48[0x1c];
    void* p64;
    char pad68[0x1c];
    void* p84;
    char pad88[0x1c];
    void* pa4;
    char pada8[0x1c];
    void* pc4;
};

// INFERRED: original is __thiscall (ecx = this) but the target ends in a plain jmp with no stack args;
// __fastcall self-in-ecx is the cdecl-compatible form the checker requires.
extern "C" void fn_0040a0e0();
extern "C" int g_0096c39c;

extern "C" void __cdecl fn_0040a6c0(Local_0040a6c0* self)
{
    *(void**)self = (void*)(unsigned)g_0080bb14;
    self->p10 = (void*)(unsigned)g_0080bb04;
    self->p14 = (void*)(unsigned)g_0080bafc;
    self->p20 = (void*)(unsigned)g_0080baf4;
    self->p24 = (void*)(unsigned)g_0080bae4;
    self->p44 = (void*)(unsigned)g_0080bad4;
    self->p64 = (void*)(unsigned)g_0080bac4;
    self->p84 = (void*)(unsigned)g_0080bab4;
    self->pa4 = (void*)(unsigned)g_0080baa4;
    self->pc4 = (void*)(unsigned)g_0080ba94;
    g_0096c39c = 0;
    fn_0040a0e0();
}
