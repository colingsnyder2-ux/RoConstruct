// from server: 100% by nuck16
// roc 2009-12 00680eb0  unit: RBX::Script  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00680eb0
//
// 00680eb0  c70164049d00         mov dword ptr [ecx], 0x9d0464
// 00680eb6  c7410458049d00       mov dword ptr [ecx + 4], 0x9d0458
// 00680ebd  c741184c049d00       mov dword ptr [ecx + 0x18], 0x9d044c
// 00680ec4  c7411c44049d00       mov dword ptr [ecx + 0x1c], 0x9d0444
// 00680ecb  e990fdffff           jmp 0x680c60

extern "C" void func_680c60();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d0464;
    *(int *)((char *)this + 0x4) = 0x9d0458;
    *(int *)((char *)this + 0x18) = 0x9d044c;
    *(int *)((char *)this + 0x1c) = 0x9d0444;
    func_680c60();
}
