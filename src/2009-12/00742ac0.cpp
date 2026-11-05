// from server: 100% by nuck16
// roc 2009-12 00742ac0  unit: RBX::VHole::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00742ac0
//
// 00742ac0  c701ec2c9e00         mov dword ptr [ecx], 0x9e2cec
// 00742ac6  c74104e02c9e00       mov dword ptr [ecx + 4], 0x9e2ce0
// 00742acd  c74118d42c9e00       mov dword ptr [ecx + 0x18], 0x9e2cd4
// 00742ad4  c7411ccc2c9e00       mov dword ptr [ecx + 0x1c], 0x9e2ccc
// 00742adb  c78194000000b42c9e00 mov dword ptr [ecx + 0x94], 0x9e2cb4
// 00742ae5  e9c6f7ffff           jmp 0x7422b0

extern "C" void func_7422b0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e2cec;
    *(int *)((char *)this + 0x4) = 0x9e2ce0;
    *(int *)((char *)this + 0x18) = 0x9e2cd4;
    *(int *)((char *)this + 0x1c) = 0x9e2ccc;
    *(int *)((char *)this + 0x94) = 0x9e2cb4;
    func_7422b0();
}
