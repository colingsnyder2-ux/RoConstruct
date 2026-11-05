// from server: 100% by nuck16
// roc 2009-12 0068f5f0  unit: RBX::VHopperBin::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068f5f0
//
// 0068f5f0  c70104169d00         mov dword ptr [ecx], 0x9d1604
// 0068f5f6  c74104f8159d00       mov dword ptr [ecx + 4], 0x9d15f8
// 0068f5fd  c74118ec159d00       mov dword ptr [ecx + 0x18], 0x9d15ec
// 0068f604  c7411ce4159d00       mov dword ptr [ecx + 0x1c], 0x9d15e4
// 0068f60b  c78194000000dc159d00 mov dword ptr [ecx + 0x94], 0x9d15dc
// 0068f615  e9466b0e00           jmp 0x776160

extern "C" void func_776160();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d1604;
    *(int *)((char *)this + 0x4) = 0x9d15f8;
    *(int *)((char *)this + 0x18) = 0x9d15ec;
    *(int *)((char *)this + 0x1c) = 0x9d15e4;
    *(int *)((char *)this + 0x94) = 0x9d15dc;
    func_776160();
}
