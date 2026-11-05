// from server: 100% by nuck16
// roc 2009-12 0075d250  unit: RBX::VLuaDragger::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075d250
//
// 0075d250  c7014c6d9e00         mov dword ptr [ecx], 0x9e6d4c
// 0075d256  c74104406d9e00       mov dword ptr [ecx + 4], 0x9e6d40
// 0075d25d  c74118346d9e00       mov dword ptr [ecx + 0x18], 0x9e6d34
// 0075d264  c7411c2c6d9e00       mov dword ptr [ecx + 0x1c], 0x9e6d2c
// 0075d26b  e990a8edff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e6d4c;
    *(int *)((char *)this + 0x4) = 0x9e6d40;
    *(int *)((char *)this + 0x18) = 0x9e6d34;
    *(int *)((char *)this + 0x1c) = 0x9e6d2c;
    func_637b00();
}
