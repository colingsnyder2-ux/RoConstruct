// from server: 100% by nuck16
// roc 2009-12 00746f60  unit: RBX::VGeometryService::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00746f60
//
// 00746f60  c7018c3a9e00         mov dword ptr [ecx], 0x9e3a8c
// 00746f66  c74104803a9e00       mov dword ptr [ecx + 4], 0x9e3a80
// 00746f6d  c74118743a9e00       mov dword ptr [ecx + 0x18], 0x9e3a74
// 00746f74  c7411c6c3a9e00       mov dword ptr [ecx + 0x1c], 0x9e3a6c
// 00746f7b  e9800befff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e3a8c;
    *(int *)((char *)this + 0x4) = 0x9e3a80;
    *(int *)((char *)this + 0x18) = 0x9e3a74;
    *(int *)((char *)this + 0x1c) = 0x9e3a6c;
    func_637b00();
}
