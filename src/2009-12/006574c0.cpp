// from server: 100% by nuck16
// roc 2009-12 006574c0  unit: RBX::VLocalBackpackTool::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006574c0
//
// 006574c0  c70174d29c00         mov dword ptr [ecx], 0x9cd274
// 006574c6  c7410468d29c00       mov dword ptr [ecx + 4], 0x9cd268
// 006574cd  c741185cd29c00       mov dword ptr [ecx + 0x18], 0x9cd25c
// 006574d4  c7411c54d29c00       mov dword ptr [ecx + 0x1c], 0x9cd254
// 006574db  c781940000004cd29c00 mov dword ptr [ecx + 0x94], 0x9cd24c
// 006574e5  e98681dbff           jmp 0x40f670

extern "C" void func_40f670();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cd274;
    *(int *)((char *)this + 0x4) = 0x9cd268;
    *(int *)((char *)this + 0x18) = 0x9cd25c;
    *(int *)((char *)this + 0x1c) = 0x9cd254;
    *(int *)((char *)this + 0x94) = 0x9cd24c;
    func_40f670();
}
