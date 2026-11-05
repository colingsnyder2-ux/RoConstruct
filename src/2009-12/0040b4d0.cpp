// from server: 100% by nuck16
// roc 2009-12 0040b4d0  unit: RBX::Reflection::Metadata::VFunctions::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040b4d0
//
// 0040b4d0  c701b4029a00         mov dword ptr [ecx], 0x9a02b4
// 0040b4d6  c74104ac029a00       mov dword ptr [ecx + 4], 0x9a02ac
// 0040b4dd  c74118a0029a00       mov dword ptr [ecx + 0x18], 0x9a02a0
// 0040b4e4  c7411c98029a00       mov dword ptr [ecx + 0x1c], 0x9a0298
// 0040b4eb  e910c62200           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9a02b4;
    *(int *)((char *)this + 0x4) = 0x9a02ac;
    *(int *)((char *)this + 0x18) = 0x9a02a0;
    *(int *)((char *)this + 0x1c) = 0x9a0298;
    func_637b00();
}
