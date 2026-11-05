// from server: 100% by nuck16
// roc 2009-12 0065c8a0  unit: RBX::VBrickColor::V?$Value::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065c8a0
//
// 0065c8a0  c7014cde9c00         mov dword ptr [ecx], 0x9cde4c
// 0065c8a6  c7410444de9c00       mov dword ptr [ecx + 4], 0x9cde44
// 0065c8ad  c7411838de9c00       mov dword ptr [ecx + 0x18], 0x9cde38
// 0065c8b4  c7411c30de9c00       mov dword ptr [ecx + 0x1c], 0x9cde30
// 0065c8bb  e940b2fdff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cde4c;
    *(int *)((char *)this + 0x4) = 0x9cde44;
    *(int *)((char *)this + 0x18) = 0x9cde38;
    *(int *)((char *)this + 0x1c) = 0x9cde30;
    func_637b00();
}
