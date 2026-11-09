// from server: 100% by nuck16
// roc 2009-12 006d9d30  unit: RBX::VHumanoidController::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d9d30
//
// 006d9d30  c7012c979d00         mov dword ptr [ecx], 0x9d972c
// 006d9d36  c7410424979d00       mov dword ptr [ecx + 4], 0x9d9724
// 006d9d3d  c7411818979d00       mov dword ptr [ecx + 0x18], 0x9d9718
// 006d9d44  c7411c10979d00       mov dword ptr [ecx + 0x1c], 0x9d9710
// 006d9d4b  c7819400000004979d00 mov dword ptr [ecx + 0x94], 0x9d9704
// 006d9d55  e946ffffff           jmp 0x6d9ca0

extern "C" void func_6d9ca0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d972c;
    *(int *)((char *)this + 0x4) = 0x9d9724;
    *(int *)((char *)this + 0x18) = 0x9d9718;
    *(int *)((char *)this + 0x1c) = 0x9d9710;
    *(int *)((char *)this + 0x94) = 0x9d9704;
    func_6d9ca0();
}
