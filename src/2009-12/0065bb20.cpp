// from server: 100% by nuck16
// roc 2009-12 0065bb20  unit: std::D::DU?$char_traits::V?$basic_string::V?$Value::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065bb20
//
// 0065bb20  c7011cdb9c00         mov dword ptr [ecx], 0x9cdb1c
// 0065bb26  c7410414db9c00       mov dword ptr [ecx + 4], 0x9cdb14
// 0065bb2d  c7411808db9c00       mov dword ptr [ecx + 0x18], 0x9cdb08
// 0065bb34  c7411c00db9c00       mov dword ptr [ecx + 0x1c], 0x9cdb00
// 0065bb3b  e9c0bffdff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cdb1c;
    *(int *)((char *)this + 0x4) = 0x9cdb14;
    *(int *)((char *)this + 0x18) = 0x9cdb08;
    *(int *)((char *)this + 0x1c) = 0x9cdb00;
    func_637b00();
}
