// from server: 100% by nuck16
// roc 2009-12 007532a0  unit: RBX::VTouchTransmitter::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007532a0
//
// 007532a0  c7016c479e00         mov dword ptr [ecx], 0x9e476c
// 007532a6  c7410464479e00       mov dword ptr [ecx + 4], 0x9e4764
// 007532ad  c7411858479e00       mov dword ptr [ecx + 0x18], 0x9e4758
// 007532b4  c7411c50479e00       mov dword ptr [ecx + 0x1c], 0x9e4750
// 007532bb  e94048eeff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e476c;
    *(int *)((char *)this + 0x4) = 0x9e4764;
    *(int *)((char *)this + 0x18) = 0x9e4758;
    *(int *)((char *)this + 0x1c) = 0x9e4750;
    func_637b00();
}
