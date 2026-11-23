// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no authentic header available; raw layout, best-effort draft (unverified).
extern "C" int __fastcall fn_004eaae0(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_004ea9a0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004eaa40(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0042b680(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

// INFERRED: unknown globals (vtable and float constant)
extern "C" char g_00826f2c[];
extern "C" const float g_0082d1cc;

extern "C" int __fastcall fn_004eafd0(char* self, int unusedEdx, int part, char* inst, int arg3)
{
    // INFERRED: base ctor takes (float, shared_ptr<PartInstance>) + arg3
    fn_004eaae0(self, 0, (int)g_0082d1cc, part, arg3);
    *(void**)self = g_00826f2c;
    // INFERRED: scoped_connection members at +0xe0 and +0xf4; shared_ptr at +0xd8
    int slot1[4];
    int conn1 = fn_004ea9a0(slot1, 0, 0);
    fn_004eaa40(self + 0xf4, 0, conn1);
    fn_0042b680(self + 0xe0, 0, (int)(inst ? inst + 0x14 : 0), 0, 10);
    return (int)self;
}
