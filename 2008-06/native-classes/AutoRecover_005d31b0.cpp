// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00846144[];   // INFERRED: unnamed global at 0x00846144 in the original
extern "C" char g_0083be90[];   // INFERRED: unnamed global at 0x0083be90 in the original
extern "C" char g_0083beac[];   // INFERRED: unnamed global at 0x0083beac in the original
extern "C" char g_0083beb4[];   // INFERRED: unnamed global at 0x0083beb4 in the original
extern "C" char g_0083bec0[];   // INFERRED: unnamed global at 0x0083bec0 in the original
extern "C" char g_0083bed8[];   // INFERRED: unnamed global at 0x0083bed8 in the original
extern "C" char g_0083bee4[];   // INFERRED: unnamed global at 0x0083bee4 in the original
extern "C" char g_0083bef4[];   // INFERRED: unnamed global at 0x0083bef4 in the original
extern "C" char g_0083bf00[];   // INFERRED: unnamed global at 0x0083bf00 in the original
extern "C" char g_0083bf10[];   // INFERRED: unnamed global at 0x0083bf10 in the original
extern "C" char g_0083bf20[];   // INFERRED: unnamed global at 0x0083bf20 in the original
extern "C" char g_0083bf30[];   // INFERRED: unnamed global at 0x0083bf30 in the original
extern "C" char g_0083bf40[];   // INFERRED: unnamed global at 0x0083bf40 in the original
extern "C" char g_0083bf50[];   // INFERRED: unnamed global at 0x0083bf50 in the original
extern "C" char g_0083bf60[];   // INFERRED: unnamed global at 0x0083bf60 in the original
extern "C" char g_0083bf68[];   // INFERRED: unnamed global at 0x0083bf68 in the original
extern "C" char g_0083bf70[];   // INFERRED: unnamed global at 0x0083bf70 in the original
extern "C" char g_0083bf7c[];   // INFERRED: unnamed global at 0x0083bf7c in the original
extern "C" char g_00849e6c[];   // INFERRED: unnamed global at 0x00849e6c in the original
// INFERRED: class layout unknown; modeled as raw dword array with the analog's structure.
extern "C" int __stdcall fn_005d1fa0(int a1);
extern "C" unsigned int __cdecl fn_005d2760();

struct Local_005d31b0
{
    unsigned int data[257];
    ~Local_005d31b0();
};

struct Local_005d31b0_Cleanup
{
    Local_005d31b0* object;
    Local_005d31b0_Cleanup(Local_005d31b0* p, int initialize);
    ~Local_005d31b0_Cleanup();
};

inline Local_005d31b0_Cleanup::Local_005d31b0_Cleanup(Local_005d31b0* p, int initialize) : object(p)
{
    volatile int state = 0;
    if (initialize)
    {
        p->data[0x134 / 4] = ((int)&g_00849e6c);
        p->data[0x400 / 4] = ((int)&g_00846144);
    }
    fn_005d1fa0(0);
}

inline Local_005d31b0_Cleanup::~Local_005d31b0_Cleanup()
{
    if (object)
        object->~Local_005d31b0();
}

extern "C" Local_005d31b0* __fastcall fn_005d31b0(Local_005d31b0* self, int unusedEdx, int initialize)
{
    Local_005d31b0_Cleanup cleanup(self, initialize);
    self->data[0x1c / 4] = fn_005d2760();
    self->data[0] = ((int)&g_0083bf7c);
    self->data[0x10 / 4] = ((int)&g_0083bf70);
    self->data[0x14 / 4] = ((int)&g_0083bf68);
    self->data[0x20 / 4] = ((int)&g_0083bf60);
    self->data[0x24 / 4] = ((int)&g_0083bf50);
    self->data[0x44 / 4] = ((int)&g_0083bf40);
    self->data[0x64 / 4] = ((int)&g_0083bf30);
    self->data[0x84 / 4] = ((int)&g_0083bf20);
    self->data[0xa4 / 4] = ((int)&g_0083bf10);
    self->data[0xc4 / 4] = ((int)&g_0083bf00);
    self->data[0x130 / 4] = ((int)&g_0083bef4);
    self->data[0x1a0 / 4] = ((int)&g_0083bee4);
    self->data[0x1c0 / 4] = ((int)&g_0083bed8);
    self->data[0x1cc / 4] = ((int)&g_0083bec0);

    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[1]) = ((int)&g_0083beb4);
    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[2]) = ((int)&g_0083beac);
    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[3]) = ((int)&g_0083be90);

    int offset = ((int*)self->data[0x134 / 4])[1];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2b8;
    offset = ((int*)self->data[0x134 / 4])[2];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c0;
    offset = ((int*)self->data[0x134 / 4])[3];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c8;

    cleanup.object = 0;
    return self;
}
