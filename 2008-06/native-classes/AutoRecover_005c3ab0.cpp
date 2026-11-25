// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: the owning class is unknown, so this local layout only keeps the member
// offsets the disassembly touches (vtable slots up to 0xc4, plus 0x130 and 0x134).
struct ScriptLikeObject {
    void* storage[0x130 / 4];
    void* member130;
    void* member134;
};

// INFERRED: the original stores the addresses of vtables (secondary base vtables).
// They are declared as unknown globals because their real symbols are not visible here.
extern "C" char g_00838c04[];
extern "C" char g_00838bf8[];
extern "C" char g_00838bf0[];
extern "C" char g_00838be8[];
extern "C" char g_00838bd8[];
extern "C" char g_00838bc8[];
extern "C" char g_00838bb8[];
extern "C" char g_00838ba8[];
extern "C" char g_00838b98[];
extern "C" char g_00838b88[];

// 0x005c3960: DescribedCreatable<Script, Instance, sScript> base constructor
extern "C" void __fastcall fn_005c3960(ScriptLikeObject* self, int unusedEdx);

// INFERRED: 0x0055af90 is Instance::setName(const std::string&). Its class layout is
// not visible here, so it is declared with the fn_ convention instead.
extern "C" void __fastcall fn_0055af90(ScriptLikeObject* self, int unusedEdx, const std::string& value);

extern "C" ScriptLikeObject* __fastcall fn_005c3ab0(ScriptLikeObject* self, int unusedEdx)
{
    fn_005c3960(self, 0);

    self->storage[0x00 / 4] = g_00838c04;
    self->storage[0x10 / 4] = g_00838bf8;
    self->storage[0x14 / 4] = g_00838bf0;
    self->storage[0x20 / 4] = g_00838be8;
    self->storage[0x24 / 4] = g_00838bd8;
    self->storage[0x44 / 4] = g_00838bc8;
    self->storage[0x64 / 4] = g_00838bb8;
    self->storage[0x84 / 4] = g_00838ba8;
    self->storage[0xa4 / 4] = g_00838b98;
    self->storage[0xc4 / 4] = g_00838b88;
    self->member130 = 0;
    self->member134 = 0;

    {
        std::string name("Value");
        fn_0055af90(self, 0, name);
    }
    return self;
}
