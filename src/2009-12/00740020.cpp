// from server: 100% by nuck16
// roc 2009-12 00740020  unit: RBX::VCollectionService::?$EventDesc  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00740020
//
// 00740020  c701f4269e00         mov dword ptr [ecx], 0x9e26f4
// 00740026  c74104ec269e00       mov dword ptr [ecx + 4], 0x9e26ec
// 0074002d  c74118e0269e00       mov dword ptr [ecx + 0x18], 0x9e26e0
// 00740034  c7411cd8269e00       mov dword ptr [ecx + 0x1c], 0x9e26d8
// 0074003b  e9c07aefff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e26f4;
    *(int *)((char *)this + 0x4) = 0x9e26ec;
    *(int *)((char *)this + 0x18) = 0x9e26e0;
    *(int *)((char *)this + 0x1c) = 0x9e26d8;
    func_637b00();
}
