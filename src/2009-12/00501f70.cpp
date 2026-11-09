// from server: 100% by nuck16
// roc 2009-12 00501f70  unit: RBX::VPants::?$FactoryProduct  size: 42 bytes
//
// 00501f70  c701a4a59b00         mov dword ptr [ecx], 0x9ba5a4
// 00501f76  c7410498a59b00       mov dword ptr [ecx + 4], 0x9ba598
// 00501f7d  c741188ca59b00       mov dword ptr [ecx + 0x18], 0x9ba58c
// 00501f84  c7411c84a59b00       mov dword ptr [ecx + 0x1c], 0x9ba584
// 00501f8b  c781940000007ca59b00 mov dword ptr [ecx + 0x94], 0x9ba57c
// 00501f95  e946ffffff           jmp 0x501ee0

extern "C" void func_501ee0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9ba5a4;
    *(int *)((char *)this + 0x4) = 0x9ba598;
    *(int *)((char *)this + 0x18) = 0x9ba58c;
    *(int *)((char *)this + 0x1c) = 0x9ba584;
    *(int *)((char *)this + 0x94) = 0x9ba57c;
    func_501ee0();
}
