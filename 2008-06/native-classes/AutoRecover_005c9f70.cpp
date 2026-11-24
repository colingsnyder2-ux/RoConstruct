// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: ctor of DescribedCreatable<Script> derived class with one int member at 0x158; vtable pointers per disassembly.
struct ScriptDerived {
    int pad;
};

extern "C" char g_00839f0c[];
extern "C" char g_00839efc[];
extern "C" char g_00839ef4[];
extern "C" char g_00839eec[];
extern "C" char g_00839edc[];
extern "C" char g_00839ecc[];
extern "C" char g_00839ebc[];
extern "C" char g_00839eac[];
extern "C" char g_00839e9c[];
extern "C" char g_00839e8c[];

// INFERRED: base ctor takes only ecx (original does not set edx), so declare a one-arg __fastcall.
extern "C" void __fastcall fn_005c9ed0(ScriptDerived* self);

extern "C" ScriptDerived* __fastcall fn_005c9f70(ScriptDerived* self, int unusedEdx, int value)
{
    fn_005c9ed0(self);
    *(int*)((char*)self + 0x158) = value;
    *(void**)((char*)self + 0x00) = g_00839f0c;
    *(void**)((char*)self + 0x10) = g_00839efc;
    *(void**)((char*)self + 0x14) = g_00839ef4;
    *(void**)((char*)self + 0x20) = g_00839eec;
    *(void**)((char*)self + 0x24) = g_00839edc;
    *(void**)((char*)self + 0x44) = g_00839ecc;
    *(void**)((char*)self + 0x64) = g_00839ebc;
    *(void**)((char*)self + 0x84) = g_00839eac;
    *(void**)((char*)self + 0xa4) = g_00839e9c;
    *(void**)((char*)self + 0xc4) = g_00839e8c;
    return self;
}
