// from server: 100% by nuck16
// roc 2009-12 00759730  unit: RBX::VGuiTextButton::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00759730
//
// 00759730  c7010c5d9e00         mov dword ptr [ecx], 0x9e5d0c
// 00759736  c74104005d9e00       mov dword ptr [ecx + 4], 0x9e5d00
// 0075973d  c74118f45c9e00       mov dword ptr [ecx + 0x18], 0x9e5cf4
// 00759744  c7411cec5c9e00       mov dword ptr [ecx + 0x1c], 0x9e5cec
// 0075974b  c78194000000dc5c9e00 mov dword ptr [ecx + 0x94], 0x9e5cdc
// 00759755  c78198000000c45c9e00 mov dword ptr [ecx + 0x98], 0x9e5cc4
// 0075975f  e9fce6ffff           jmp 0x757e60

extern "C" void func_757e60();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e5d0c;
    *(int *)((char *)this + 0x4) = 0x9e5d00;
    *(int *)((char *)this + 0x18) = 0x9e5cf4;
    *(int *)((char *)this + 0x1c) = 0x9e5cec;
    *(int *)((char *)this + 0x94) = 0x9e5cdc;
    *(int *)((char *)this + 0x98) = 0x9e5cc4;
    func_757e60();
}
