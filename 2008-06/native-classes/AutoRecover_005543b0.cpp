// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was provided. Vtable slots are written through
// unknown-global vtable symbols at the offsets shown in the disassembly.

extern "C" void __fastcall fn_0055b7e0(void* self, int unusedEdx); // RBX::Instance::Instance()

extern "C" char g_0082d3b4[];
extern "C" char g_0082d3a8[];
extern "C" char g_0082d3a0[];
extern "C" char g_0082d398[];
extern "C" char g_0082d388[];
extern "C" char g_0082d378[];
extern "C" char g_0082d368[];
extern "C" char g_0082d358[];
extern "C" char g_0082d348[];
extern "C" char g_0082d338[];

extern "C" void* __fastcall fn_005543b0(void* self, int unusedEdx)
{
    fn_0055b7e0(self, 0);
    void** p = (void**)self;
    p[0x00 / 4] = g_0082d3b4;
    p[0x10 / 4] = g_0082d3a8;
    p[0x14 / 4] = g_0082d3a0;
    p[0x20 / 4] = g_0082d398;
    p[0x24 / 4] = g_0082d388;
    p[0x44 / 4] = g_0082d378;
    p[0x64 / 4] = g_0082d368;
    p[0x84 / 4] = g_0082d358;
    p[0xa4 / 4] = g_0082d348;
    p[0xc4 / 4] = g_0082d338;
    return self;
}
