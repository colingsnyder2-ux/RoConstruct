// from server: 100% by nuck16
// roc 2009-12 0065b870  unit: RBX::N$1?sDoubleValue::V?$Value::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065b870
//
// 0065b870  c70194da9c00         mov dword ptr [ecx], 0x9cda94
// 0065b876  c741048cda9c00       mov dword ptr [ecx + 4], 0x9cda8c
// 0065b87d  c7411880da9c00       mov dword ptr [ecx + 0x18], 0x9cda80
// 0065b884  c7411c78da9c00       mov dword ptr [ecx + 0x1c], 0x9cda78
// 0065b88b  e970c2fdff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cda94;
    *(int *)((char *)this + 0x4) = 0x9cda8c;
    *(int *)((char *)this + 0x18) = 0x9cda80;
    *(int *)((char *)this + 0x1c) = 0x9cda78;
    func_637b00();
}
