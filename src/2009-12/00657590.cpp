// from server: 100% by nuck16
// roc 2009-12 00657590  unit: RBX::VLocalBackpackTool::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00657590
//
// 00657590  c70144d39c00         mov dword ptr [ecx], 0x9cd344
// 00657596  c7410438d39c00       mov dword ptr [ecx + 4], 0x9cd338
// 0065759d  c741182cd39c00       mov dword ptr [ecx + 0x18], 0x9cd32c
// 006575a4  c7411c24d39c00       mov dword ptr [ecx + 0x1c], 0x9cd324
// 006575ab  c781940000001cd39c00 mov dword ptr [ecx + 0x94], 0x9cd31c
// 006575b5  e9b680dbff           jmp 0x40f670

extern "C" void func_40f670();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cd344;
    *(int *)((char *)this + 0x4) = 0x9cd338;
    *(int *)((char *)this + 0x18) = 0x9cd32c;
    *(int *)((char *)this + 0x1c) = 0x9cd324;
    *(int *)((char *)this + 0x94) = 0x9cd31c;
    func_40f670();
}
