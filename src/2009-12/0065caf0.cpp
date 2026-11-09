// from server: 100% by nuck16
// roc 2009-12 0065caf0  unit: RBX::H$1?sIntConstrainedValue::V?$ConstrainedValue::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065caf0
//
// 0065caf0  c701d4de9c00         mov dword ptr [ecx], 0x9cded4
// 0065caf6  c74104ccde9c00       mov dword ptr [ecx + 4], 0x9cdecc
// 0065cafd  c74118c0de9c00       mov dword ptr [ecx + 0x18], 0x9cdec0
// 0065cb04  c7411cb8de9c00       mov dword ptr [ecx + 0x1c], 0x9cdeb8
// 0065cb0b  e9f0affdff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cded4;
    *(int *)((char *)this + 0x4) = 0x9cdecc;
    *(int *)((char *)this + 0x18) = 0x9cdec0;
    *(int *)((char *)this + 0x1c) = 0x9cdeb8;
    func_637b00();
}
