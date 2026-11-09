// from server: 100% by nuck16
// roc 2009-12 006ffc00  unit: RBX::Reflection::Metadata::VClass::?$BoundPropGetSet  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ffc00
//
// 006ffc00  c70144dc9d00         mov dword ptr [ecx], 0x9ddc44
// 006ffc06  c7410438dc9d00       mov dword ptr [ecx + 4], 0x9ddc38
// 006ffc0d  c741182cdc9d00       mov dword ptr [ecx + 0x18], 0x9ddc2c
// 006ffc14  c7411c24dc9d00       mov dword ptr [ecx + 0x1c], 0x9ddc24
// 006ffc1b  e9e07ef3ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9ddc44;
    *(int *)((char *)this + 0x4) = 0x9ddc38;
    *(int *)((char *)this + 0x18) = 0x9ddc2c;
    *(int *)((char *)this + 0x1c) = 0x9ddc24;
    func_637b00();
}
