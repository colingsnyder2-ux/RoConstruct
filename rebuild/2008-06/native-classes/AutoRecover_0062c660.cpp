// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00846144[];   // INFERRED: unnamed global at 0x00846144 in the original
extern "C" char g_00846264[];   // INFERRED: unnamed global at 0x00846264 in the original
extern "C" char g_00846280[];   // INFERRED: unnamed global at 0x00846280 in the original
extern "C" char g_00846288[];   // INFERRED: unnamed global at 0x00846288 in the original
extern "C" char g_00846294[];   // INFERRED: unnamed global at 0x00846294 in the original
extern "C" char g_008462ac[];   // INFERRED: unnamed global at 0x008462ac in the original
extern "C" char g_008462b8[];   // INFERRED: unnamed global at 0x008462b8 in the original
extern "C" char g_008462c8[];   // INFERRED: unnamed global at 0x008462c8 in the original
extern "C" char g_008462d4[];   // INFERRED: unnamed global at 0x008462d4 in the original
extern "C" char g_008462e4[];   // INFERRED: unnamed global at 0x008462e4 in the original
extern "C" char g_008462f4[];   // INFERRED: unnamed global at 0x008462f4 in the original
extern "C" char g_00846304[];   // INFERRED: unnamed global at 0x00846304 in the original
extern "C" char g_00846314[];   // INFERRED: unnamed global at 0x00846314 in the original
extern "C" char g_00846324[];   // INFERRED: unnamed global at 0x00846324 in the original
extern "C" char g_00846334[];   // INFERRED: unnamed global at 0x00846334 in the original
extern "C" char g_0084633c[];   // INFERRED: unnamed global at 0x0084633c in the original
extern "C" char g_00846344[];   // INFERRED: unnamed global at 0x00846344 in the original
extern "C" char g_00846354[];   // INFERRED: unnamed global at 0x00846354 in the original
extern "C" char g_00849e6c[];   // INFERRED: unnamed global at 0x00849e6c in the original
// INFERRED: class layout unknown; modeled as raw dword array with the analog's structure.
extern "C" int __stdcall fn_0062bc80(int a1);
extern "C" unsigned int __cdecl fn_005c38f0();

struct Local_0062c660
{
    unsigned int data[257];
    ~Local_0062c660();
};

struct Local_0062c660_Cleanup
{
    Local_0062c660* object;
    Local_0062c660_Cleanup(Local_0062c660* p, int initialize);
    ~Local_0062c660_Cleanup();
};

inline Local_0062c660_Cleanup::Local_0062c660_Cleanup(Local_0062c660* p, int initialize) : object(p)
{
    volatile int state = 0;
    if (initialize)
    {
        p->data[0x134 / 4] = ((int)&g_00849e6c);
        p->data[0x400 / 4] = ((int)&g_00846144);
    }
    fn_0062bc80(0);
}

inline Local_0062c660_Cleanup::~Local_0062c660_Cleanup()
{
    if (object)
        object->~Local_0062c660();
}

extern "C" Local_0062c660* __fastcall fn_0062c660(Local_0062c660* self, int unusedEdx, int initialize)
{
    Local_0062c660_Cleanup cleanup(self, initialize);
    self->data[0x1c / 4] = fn_005c38f0();
    self->data[0] = ((int)&g_00846354);
    self->data[0x10 / 4] = ((int)&g_00846344);
    self->data[0x14 / 4] = ((int)&g_0084633c);
    self->data[0x20 / 4] = ((int)&g_00846334);
    self->data[0x24 / 4] = ((int)&g_00846324);
    self->data[0x44 / 4] = ((int)&g_00846314);
    self->data[0x64 / 4] = ((int)&g_00846304);
    self->data[0x84 / 4] = ((int)&g_008462f4);
    self->data[0xa4 / 4] = ((int)&g_008462e4);
    self->data[0xc4 / 4] = ((int)&g_008462d4);
    self->data[0x130 / 4] = ((int)&g_008462c8);
    self->data[0x1a0 / 4] = ((int)&g_008462b8);
    self->data[0x1c0 / 4] = ((int)&g_008462ac);
    self->data[0x1cc / 4] = ((int)&g_00846294);

    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[1]) = ((int)&g_00846288);
    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[2]) = ((int)&g_00846280);
    *(unsigned int*)((char*)self + 0x134 + ((int*)self->data[0x134 / 4])[3]) = ((int)&g_00846264);

    int offset = ((int*)self->data[0x134 / 4])[1];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2b8;
    offset = ((int*)self->data[0x134 / 4])[2];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c0;
    offset = ((int*)self->data[0x134 / 4])[3];
    *(int*)((char*)self + 0x130 + offset) = offset - 0x2c8;

    cleanup.object = 0;
    return self;
}
