// from server: 100% by nuck16
// roc 2009-12 007577a0  unit: RBX::VFrame::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007577a0
//
// 007577a0  c7011c549e00         mov dword ptr [ecx], 0x9e541c
// 007577a6  c7410410549e00       mov dword ptr [ecx + 4], 0x9e5410
// 007577ad  c7411804549e00       mov dword ptr [ecx + 0x18], 0x9e5404
// 007577b4  c7411cfc539e00       mov dword ptr [ecx + 0x1c], 0x9e53fc
// 007577bb  c78194000000ec539e00 mov dword ptr [ecx + 0x94], 0x9e53ec
// 007577c5  c78198000000d4539e00 mov dword ptr [ecx + 0x98], 0x9e53d4
// 007577cf  e9bcfeffff           jmp 0x757690

extern "C" void func_757690();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e541c;
    *(int *)((char *)this + 0x4) = 0x9e5410;
    *(int *)((char *)this + 0x18) = 0x9e5404;
    *(int *)((char *)this + 0x1c) = 0x9e53fc;
    *(int *)((char *)this + 0x94) = 0x9e53ec;
    *(int *)((char *)this + 0x98) = 0x9e53d4;
    func_757690();
}
