// from server: 100% by nuck16
// roc 2009-12 00409a40  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00409a40
//
// 00409a40  c701fcfd9900         mov dword ptr [ecx], 0x99fdfc
// 00409a46  c74104f4fd9900       mov dword ptr [ecx + 4], 0x99fdf4
// 00409a4d  c74118e8fd9900       mov dword ptr [ecx + 0x18], 0x99fde8
// 00409a54  c7411ce0fd9900       mov dword ptr [ecx + 0x1c], 0x99fde0
// 00409a5b  e9a0e02200           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x99fdfc;
    *(int *)((char *)this + 0x4) = 0x99fdf4;
    *(int *)((char *)this + 0x18) = 0x99fde8;
    *(int *)((char *)this + 0x1c) = 0x99fde0;
    func_637b00();
}
