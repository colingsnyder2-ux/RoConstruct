// from server: 100% by nuck16
// roc 2009-12 007161a0  unit: RBX::JointInstance  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007161a0
//
// 007161a0  c701eced9d00         mov dword ptr [ecx], 0x9dedec
// 007161a6  c74104e0ed9d00       mov dword ptr [ecx + 4], 0x9dede0
// 007161ad  c74118d4ed9d00       mov dword ptr [ecx + 0x18], 0x9dedd4
// 007161b4  c7411ccced9d00       mov dword ptr [ecx + 0x1c], 0x9dedcc
// 007161bb  c78194000000b4ed9d00 mov dword ptr [ecx + 0x94], 0x9dedb4
// 007161c5  e9c6f7ffff           jmp 0x715990

extern "C" void func_715990();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dedec;
    *(int *)((char *)this + 0x4) = 0x9dede0;
    *(int *)((char *)this + 0x18) = 0x9dedd4;
    *(int *)((char *)this + 0x1c) = 0x9dedcc;
    *(int *)((char *)this + 0x94) = 0x9dedb4;
    func_715990();
}
