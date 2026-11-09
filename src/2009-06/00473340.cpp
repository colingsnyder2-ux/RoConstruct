// from server: 100% by EspClaude
// roc 2009-06 00473340  unit: RBX::LDraw2Lua::LuaWriter  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00473340
//
// 00473340  8b442404             mov eax, dword ptr [esp + 4]
// 00473344  8d542404             lea edx, [esp + 4]
// 00473348  52                   push edx
// 00473349  83c120               add ecx, 0x20
// 0047334c  89442408             mov dword ptr [esp + 8], eax
// 00473350  e81b0afcff           call 0x433d70
// 00473355  c20400               ret 4
// copied from an identical function in another client (function ?write@Writer@ns_ROCX00000c@@QAEXH@Z)

namespace ns_ROCX00000c {
struct Listener
{
    void invoke(const int& value);
};

struct Writer
{
    char padding[32];
    Listener listener;
    void write(int value);
};

void Writer::write(int value)
{
    int copy = value;
    listener.invoke(copy);
}
}
