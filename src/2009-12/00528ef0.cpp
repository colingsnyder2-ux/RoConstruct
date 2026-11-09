// from server: 100% by nuck16
// roc 2009-12 00528ef0  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00528ef0
//
// 00528ef0  c70194c09b00         mov dword ptr [ecx], 0x9bc094
// 00528ef6  c7410488c09b00       mov dword ptr [ecx + 4], 0x9bc088
// 00528efd  c741187cc09b00       mov dword ptr [ecx + 0x18], 0x9bc07c
// 00528f04  c7411c74c09b00       mov dword ptr [ecx + 0x1c], 0x9bc074
// 00528f0b  e9f0eb1000           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9bc094;
    *(int *)((char *)this + 0x4) = 0x9bc088;
    *(int *)((char *)this + 0x18) = 0x9bc07c;
    *(int *)((char *)this + 0x1c) = 0x9bc074;
    func_637b00();
}
