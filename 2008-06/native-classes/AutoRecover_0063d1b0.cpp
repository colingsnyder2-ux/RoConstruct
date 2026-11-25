// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00846144[];   // INFERRED: unnamed global at 0x00846144 in the original
extern "C" char g_00849d14[];   // INFERRED: unnamed global at 0x00849d14 in the original
extern "C" char g_00849d30[];   // INFERRED: unnamed global at 0x00849d30 in the original
extern "C" char g_00849d38[];   // INFERRED: unnamed global at 0x00849d38 in the original
extern "C" char g_00849d44[];   // INFERRED: unnamed global at 0x00849d44 in the original
extern "C" char g_00849d5c[];   // INFERRED: unnamed global at 0x00849d5c in the original
extern "C" char g_00849d68[];   // INFERRED: unnamed global at 0x00849d68 in the original
extern "C" char g_00849d78[];   // INFERRED: unnamed global at 0x00849d78 in the original
extern "C" char g_00849d84[];   // INFERRED: unnamed global at 0x00849d84 in the original
extern "C" char g_00849d94[];   // INFERRED: unnamed global at 0x00849d94 in the original
extern "C" char g_00849da4[];   // INFERRED: unnamed global at 0x00849da4 in the original
extern "C" char g_00849db4[];   // INFERRED: unnamed global at 0x00849db4 in the original
extern "C" char g_00849dc4[];   // INFERRED: unnamed global at 0x00849dc4 in the original
extern "C" char g_00849dd4[];   // INFERRED: unnamed global at 0x00849dd4 in the original
extern "C" char g_00849de4[];   // INFERRED: unnamed global at 0x00849de4 in the original
extern "C" char g_00849dec[];   // INFERRED: unnamed global at 0x00849dec in the original
extern "C" char g_00849df4[];   // INFERRED: unnamed global at 0x00849df4 in the original
extern "C" char g_00849e04[];   // INFERRED: unnamed global at 0x00849e04 in the original
extern "C" char g_00849e6c[];   // INFERRED: unnamed global at 0x00849e6c in the original
// INFERRED: class layout unknown; modeled as raw dword array with the analog's structure.
extern "C" int __stdcall fn_0063c650(int a1);
extern "C" unsigned int __cdecl fn_005c3a40();

struct Local_0063d1b0
{
    unsigned int data[257];
    ~Local_0063d1b0();
};

struct Local_0063d1b0_Cleanup
{
    Local_0063d1b0* object;
    Local_0063d1b0_Cleanup(Local_0063d1b0* p, int initialize);
    ~Local_0063d1b0_Cleanup();
};

inline Local_0063d1b0_Cleanup::Local_0063d1b0_Cleanup(Local_0063d1b0* p, int initialize) : object(p)
{
    volatile int state = 0;
    if (initialize)
    {
        p->data[0x134 / 4] = ((int)&g_00849e6c);
        p->data[0x400 / 4] = ((int)&g_00846144);
    }
    fn_0063c650(0);
}

inline Local_0063d1b0_Cleanup::~Local_0063d1b0_Cleanup()
{
    if (object)
        object->~Local_0063d1b0();
}

extern "C" Local_0063d1b0* __fastcall fn_0063d1b0(Local_0063d1b0* self, int unusedEdx, int initialize)
{
    Local_0063d1b0_Cleanup cleanup(self, initialize);
    self->data[0x1c / 4] = fn_005c3a40();
    self->data[0] = ((int)&g_00849e04);
    self->data[0x10 / 4] = ((int)&g_00849df4);
    self->data[0x14 / 4] = ((int)&g_00849dec);
    self->data[0x20 / 4] = ((int)&g_00849de4);
    self->data[0x24 / 4] = ((int)&g_00849dd4);
    self->data[0x44 / 4] = ((int)&g_00849dc4);
    self->data[0x64 / 4] = ((int)&g_00849db4);
    self->data[0x84 / 4] = ((int)&g_00849da4);
    self->data[0xa4 / 4] = ((int)&g_00849d94);
    self->data[0xc4 / 4] = ((int)&g_00849d84);
    self->data[0x130 / 4] = ((int)&g_00849d78);
    self->data[0x1a0 / 4] = ((int)&g_00849d68);
    self->data[0x1c0 / 4] = ((int)&g_00849d5c);
    self->data[0x1cc / 4] = ((int)&g_00849d44);

    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[1]) = ((int)&g_00849d38);
    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[2]) = ((int)&g_00849d30);
    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[3]) = ((int)&g_00849d14);

    int offset = ((int*)self->data[0x134 / 4])[1];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2b8;
    offset = ((int*)self->data[0x134 / 4])[2];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c0;
    offset = ((int*)self->data[0x134 / 4])[3];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c8;

    cleanup.object = 0;
    return self;
}
