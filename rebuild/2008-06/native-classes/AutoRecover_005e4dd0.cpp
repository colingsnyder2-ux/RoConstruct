// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
extern "C" char g_0083e17c[];   // INFERRED: unnamed global at 0x0083e17c in the original
extern "C" char g_0083f520[];   // INFERRED: unnamed global at 0x0083f520 in the original
extern "C" char g_0083f538[];   // INFERRED: unnamed global at 0x0083f538 in the original
extern "C" char g_0083f548[];   // INFERRED: unnamed global at 0x0083f548 in the original
extern "C" char g_0083f558[];   // INFERRED: unnamed global at 0x0083f558 in the original
extern "C" char g_0083f568[];   // INFERRED: unnamed global at 0x0083f568 in the original
extern "C" char g_0083f578[];   // INFERRED: unnamed global at 0x0083f578 in the original
extern "C" char g_0083f588[];   // INFERRED: unnamed global at 0x0083f588 in the original
extern "C" char g_0083f598[];   // INFERRED: unnamed global at 0x0083f598 in the original
extern "C" char g_0083f5a0[];   // INFERRED: unnamed global at 0x0083f5a0 in the original
extern "C" char g_0083f5a8[];   // INFERRED: unnamed global at 0x0083f5a8 in the original
extern "C" char g_0083f5b4[];   // INFERRED: unnamed global at 0x0083f5b4 in the original

extern "C" void* fn_006a0920(unsigned int size);   // INFERRED: allocator (operator new analog)
extern "C" void fn_006a0900(void* p);              // INFERRED: matching delete (unwind path)

// INFERRED: file-local layout for the allocated joint (RotateJoint base + float at 0xc4)
struct Local_005e4dd0JointBase {
    unsigned int words[49];
    Local_005e4dd0JointBase();   // stands for RBX::RotateJoint::RotateJoint (0x645a70)
};

struct Local_005e4dd0Joint : Local_005e4dd0JointBase {
    float value;
    Local_005e4dd0Joint() : Local_005e4dd0JointBase(), value(0.0f)
    {
        words[0] = (unsigned int)&g_0083e17c;
    }
    static void* operator new(unsigned int n) { return fn_006a0920(n); }
    static void operator delete(void* p) { fn_006a0900(p); }
};

struct Local_005e4dd0Obj {
    unsigned int words[77];
    void Base(Local_005e4dd0JointBase* j);   // stands for fn_005e42b0 (thiscall, 1 arg)
};

extern "C" Local_005e4dd0Obj* __fastcall fn_005e4dd0(Local_005e4dd0Obj* self, int unusedEdx)
{
    self->Base(new Local_005e4dd0Joint);
    self->words[0]  = (unsigned int)&g_0083f5b4;
    self->words[4]  = (unsigned int)&g_0083f5a8;
    self->words[5]  = (unsigned int)&g_0083f5a0;
    self->words[8]  = (unsigned int)&g_0083f598;
    self->words[9]  = (unsigned int)&g_0083f588;
    self->words[17] = (unsigned int)&g_0083f578;
    self->words[25] = (unsigned int)&g_0083f568;
    self->words[33] = (unsigned int)&g_0083f558;
    self->words[41] = (unsigned int)&g_0083f548;
    self->words[49] = (unsigned int)&g_0083f538;
    self->words[76] = (unsigned int)&g_0083f520;
    return self;
}
