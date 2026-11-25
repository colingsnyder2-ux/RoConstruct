// native-flags: /O2 /Ob2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0083d4c0[];   // INFERRED: unnamed global at 0x0083d4c0 in the original
extern "C" char g_0083d4c8[];   // INFERRED: unnamed global at 0x0083d4c8 in the original
extern "C" char g_0083d4d8[];   // INFERRED: unnamed global at 0x0083d4d8 in the original
extern "C" char g_0083d4e8[];   // INFERRED: unnamed global at 0x0083d4e8 in the original
extern "C" char g_0083d4f8[];   // INFERRED: unnamed global at 0x0083d4f8 in the original
extern "C" char g_0083d508[];   // INFERRED: unnamed global at 0x0083d508 in the original
extern "C" char g_0083d518[];   // INFERRED: unnamed global at 0x0083d518 in the original
extern "C" char g_0083d528[];   // INFERRED: unnamed global at 0x0083d528 in the original
extern "C" char g_0083d530[];   // INFERRED: unnamed global at 0x0083d530 in the original
extern "C" char g_0083d538[];   // INFERRED: unnamed global at 0x0083d538 in the original
extern "C" char g_0083d544[];   // INFERRED: unnamed global at 0x0083d544 in the original
#include <string>

// INFERRED: no class header was found for this type, so a file-local layout type is used.
struct Local_005d8740 {
    char pad[0x13c + 0x18];
};

extern "C" void __fastcall fn_00409960(void* self, int unusedEdx); // NonFactoryProduct<Instance> ctor
extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_0055af90(void* self, int unusedEdx, const std::string* name); // Instance::setName

extern "C" Local_005d8740* __fastcall fn_005d8740(Local_005d8740* self, int unusedEdx)
{
    char* p = reinterpret_cast<char*>(self);
    fn_00409960(self, 0);
    *(unsigned*)(p + 0x00) = ((int)&g_0083d544);
    *(unsigned*)(p + 0x10) = ((int)&g_0083d538);
    *(unsigned*)(p + 0x14) = ((int)&g_0083d530);
    *(unsigned*)(p + 0x20) = ((int)&g_0083d528);
    *(unsigned*)(p + 0x24) = ((int)&g_0083d518);
    *(unsigned*)(p + 0x44) = ((int)&g_0083d508);
    *(unsigned*)(p + 0x64) = ((int)&g_0083d4f8);
    *(unsigned*)(p + 0x84) = ((int)&g_0083d4e8);
    *(unsigned*)(p + 0xa4) = ((int)&g_0083d4d8);
    *(unsigned*)(p + 0xc4) = ((int)&g_0083d4c8);
    *(unsigned*)(p + 0x130) = ((int)&g_0083d4c0);
    *(unsigned*)(p + 0x134) = 0;
    *(unsigned*)(p + 0x138) = 0;

    unsigned* list = (unsigned*)(p + 0x13c);
    unsigned* node = (unsigned*)fn_006a0920(4);
    if (node)
        *node = (unsigned)list;
    else
        node = 0;
    list[0] = (unsigned)node;
    list[3] = 0;
    list[4] = 0;
    list[5] = 0;

    {
        std::string name("FilteredSelection");
        fn_0055af90(self, 0, &name);
    }
    return self;
}
