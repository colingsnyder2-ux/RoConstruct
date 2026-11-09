// from server: 100% by nuck16
// roc 2009-12 00740bd0  unit: RBX::VirtualUser  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00740bd0
//
// 00740bd0  c70164289e00         mov dword ptr [ecx], 0x9e2864
// 00740bd6  c7410458289e00       mov dword ptr [ecx + 4], 0x9e2858
// 00740bdd  c741184c289e00       mov dword ptr [ecx + 0x18], 0x9e284c
// 00740be4  c7411c44289e00       mov dword ptr [ecx + 0x1c], 0x9e2844
// 00740beb  e9106fefff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e2864;
    *(int *)((char *)this + 0x4) = 0x9e2858;
    *(int *)((char *)this + 0x18) = 0x9e284c;
    *(int *)((char *)this + 0x1c) = 0x9e2844;
    func_637b00();
}
