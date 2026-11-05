// from server: 100% by nuck16
// roc 2009-12 0074d280  unit: RBX::VArcHandles::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074d280
//
// 0074d280  c70114409e00         mov dword ptr [ecx], 0x9e4014
// 0074d286  c7410408409e00       mov dword ptr [ecx + 4], 0x9e4008
// 0074d28d  c74118fc3f9e00       mov dword ptr [ecx + 0x18], 0x9e3ffc
// 0074d294  c7411cf43f9e00       mov dword ptr [ecx + 0x1c], 0x9e3ff4
// 0074d29b  c78194000000e43f9e00 mov dword ptr [ecx + 0x94], 0x9e3fe4
// 0074d2a5  c78198000000cc3f9e00 mov dword ptr [ecx + 0x98], 0x9e3fcc
// 0074d2af  e96cb9ffff           jmp 0x748c20

extern "C" void func_748c20();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e4014;
    *(int *)((char *)this + 0x4) = 0x9e4008;
    *(int *)((char *)this + 0x18) = 0x9e3ffc;
    *(int *)((char *)this + 0x1c) = 0x9e3ff4;
    *(int *)((char *)this + 0x94) = 0x9e3fe4;
    *(int *)((char *)this + 0x98) = 0x9e3fcc;
    func_748c20();
}
