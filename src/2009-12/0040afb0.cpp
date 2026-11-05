// from server: 100% by nuck16
// roc 2009-12 0040afb0  unit: RBX::Reflection::Metadata::VClass::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040afb0
//
// 0040afb0  c701a4019a00         mov dword ptr [ecx], 0x9a01a4
// 0040afb6  c741049c019a00       mov dword ptr [ecx + 4], 0x9a019c
// 0040afbd  c7411890019a00       mov dword ptr [ecx + 0x18], 0x9a0190
// 0040afc4  c7411c88019a00       mov dword ptr [ecx + 0x1c], 0x9a0188
// 0040afcb  e930cb2200           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9a01a4;
    *(int *)((char *)this + 0x4) = 0x9a019c;
    *(int *)((char *)this + 0x18) = 0x9a0190;
    *(int *)((char *)this + 0x1c) = 0x9a0188;
    func_637b00();
}
