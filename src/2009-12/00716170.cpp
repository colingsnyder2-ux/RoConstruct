// from server: 100% by nuck16
// roc 2009-12 00716170  unit: RBX::JointInstance  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00716170
//
// 00716170  c70154ec9d00         mov dword ptr [ecx], 0x9dec54
// 00716176  c7410448ec9d00       mov dword ptr [ecx + 4], 0x9dec48
// 0071617d  c741183cec9d00       mov dword ptr [ecx + 0x18], 0x9dec3c
// 00716184  c7411c34ec9d00       mov dword ptr [ecx + 0x1c], 0x9dec34
// 0071618b  c781940000001cec9d00 mov dword ptr [ecx + 0x94], 0x9dec1c
// 00716195  e9f6f7ffff           jmp 0x715990

extern "C" void func_715990();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dec54;
    *(int *)((char *)this + 0x4) = 0x9dec48;
    *(int *)((char *)this + 0x18) = 0x9dec3c;
    *(int *)((char *)this + 0x1c) = 0x9dec34;
    *(int *)((char *)this + 0x94) = 0x9dec1c;
    func_715990();
}
