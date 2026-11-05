// from server: 100% by nuck16
// roc 2009-12 0065bfc0  unit: G3D::VRay::V?$Value::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065bfc0
//
// 0065bfc0  c7012cdc9c00         mov dword ptr [ecx], 0x9cdc2c
// 0065bfc6  c7410424dc9c00       mov dword ptr [ecx + 4], 0x9cdc24
// 0065bfcd  c7411818dc9c00       mov dword ptr [ecx + 0x18], 0x9cdc18
// 0065bfd4  c7411c10dc9c00       mov dword ptr [ecx + 0x1c], 0x9cdc10
// 0065bfdb  e920bbfdff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cdc2c;
    *(int *)((char *)this + 0x4) = 0x9cdc24;
    *(int *)((char *)this + 0x18) = 0x9cdc18;
    *(int *)((char *)this + 0x1c) = 0x9cdc10;
    func_637b00();
}
