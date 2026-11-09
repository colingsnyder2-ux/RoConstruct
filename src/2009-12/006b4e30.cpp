// from server: 100% by nuck16
// roc 2009-12 006b4e30  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b4e30
//
// 006b4e30  c701d45d9d00         mov dword ptr [ecx], 0x9d5dd4
// 006b4e36  c74104c85d9d00       mov dword ptr [ecx + 4], 0x9d5dc8
// 006b4e3d  c74118bc5d9d00       mov dword ptr [ecx + 0x18], 0x9d5dbc
// 006b4e44  c7411cb45d9d00       mov dword ptr [ecx + 0x1c], 0x9d5db4
// 006b4e4b  e990f5ffff           jmp 0x6b43e0

extern "C" void func_6b43e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d5dd4;
    *(int *)((char *)this + 0x4) = 0x9d5dc8;
    *(int *)((char *)this + 0x18) = 0x9d5dbc;
    *(int *)((char *)this + 0x1c) = 0x9d5db4;
    func_6b43e0();
}
