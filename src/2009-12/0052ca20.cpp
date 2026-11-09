// from server: 100% by nuck16
// roc 2009-12 0052ca20  unit: RBX::VMessage::?$FactoryProduct::Creator  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052ca20
//
// 0052ca20  c701dcc89b00         mov dword ptr [ecx], 0x9bc8dc
// 0052ca26  c74104d4c89b00       mov dword ptr [ecx + 4], 0x9bc8d4
// 0052ca2d  c74118c8c89b00       mov dword ptr [ecx + 0x18], 0x9bc8c8
// 0052ca34  c7411cc0c89b00       mov dword ptr [ecx + 0x1c], 0x9bc8c0
// 0052ca3b  e9c0b01000           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9bc8dc;
    *(int *)((char *)this + 0x4) = 0x9bc8d4;
    *(int *)((char *)this + 0x18) = 0x9bc8c8;
    *(int *)((char *)this + 0x1c) = 0x9bc8c0;
    func_637b00();
}
