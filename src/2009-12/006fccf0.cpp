// from server: 100% by nuck16
// roc 2009-12 006fccf0  unit: RBX::VStarterGuiService::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fccf0
//
// 006fccf0  c70114d29d00         mov dword ptr [ecx], 0x9dd214
// 006fccf6  c741040cd29d00       mov dword ptr [ecx + 4], 0x9dd20c
// 006fccfd  c7411800d29d00       mov dword ptr [ecx + 0x18], 0x9dd200
// 006fcd04  c7411cf8d19d00       mov dword ptr [ecx + 0x1c], 0x9dd1f8
// 006fcd0b  e9f0adf3ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dd214;
    *(int *)((char *)this + 0x4) = 0x9dd20c;
    *(int *)((char *)this + 0x18) = 0x9dd200;
    *(int *)((char *)this + 0x1c) = 0x9dd1f8;
    func_637b00();
}
