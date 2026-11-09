// from server: 100% by nuck16
// roc 2009-12 0075c630  unit: RBX::VSelectionPartLasso::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075c630
//
// 0075c630  c7012c6a9e00         mov dword ptr [ecx], 0x9e6a2c
// 0075c636  c74104246a9e00       mov dword ptr [ecx + 4], 0x9e6a24
// 0075c63d  c74118186a9e00       mov dword ptr [ecx + 0x18], 0x9e6a18
// 0075c644  c7411c106a9e00       mov dword ptr [ecx + 0x1c], 0x9e6a10
// 0075c64b  c78194000000006a9e00 mov dword ptr [ecx + 0x94], 0x9e6a00
// 0075c655  c78198000000e8699e00 mov dword ptr [ecx + 0x98], 0x9e69e8
// 0075c65f  e91cffffff           jmp 0x75c580

extern "C" void func_75c580();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e6a2c;
    *(int *)((char *)this + 0x4) = 0x9e6a24;
    *(int *)((char *)this + 0x18) = 0x9e6a18;
    *(int *)((char *)this + 0x1c) = 0x9e6a10;
    *(int *)((char *)this + 0x94) = 0x9e6a00;
    *(int *)((char *)this + 0x98) = 0x9e69e8;
    func_75c580();
}
