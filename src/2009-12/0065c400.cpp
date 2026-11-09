// from server: 100% by nuck16
// roc 2009-12 0065c400  unit: G3D::VCoordinateFrame::V?$Value::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065c400
//
// 0065c400  c7013cdd9c00         mov dword ptr [ecx], 0x9cdd3c
// 0065c406  c7410434dd9c00       mov dword ptr [ecx + 4], 0x9cdd34
// 0065c40d  c7411828dd9c00       mov dword ptr [ecx + 0x18], 0x9cdd28
// 0065c414  c7411c20dd9c00       mov dword ptr [ecx + 0x1c], 0x9cdd20
// 0065c41b  e9e0b6fdff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9cdd3c;
    *(int *)((char *)this + 0x4) = 0x9cdd34;
    *(int *)((char *)this + 0x18) = 0x9cdd28;
    *(int *)((char *)this + 0x1c) = 0x9cdd20;
    func_637b00();
}
