// from server: 100% by nuck16
// roc 2009-12 006e37a0  unit: RBX::Humanoid  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006e37a0
//
// 006e37a0  c701d4ab9d00         mov dword ptr [ecx], 0x9dabd4
// 006e37a6  c74104ccab9d00       mov dword ptr [ecx + 4], 0x9dabcc
// 006e37ad  c74118c0ab9d00       mov dword ptr [ecx + 0x18], 0x9dabc0
// 006e37b4  c7411cb8ab9d00       mov dword ptr [ecx + 0x1c], 0x9dabb8
// 006e37bb  e94043f5ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dabd4;
    *(int *)((char *)this + 0x4) = 0x9dabcc;
    *(int *)((char *)this + 0x18) = 0x9dabc0;
    *(int *)((char *)this + 0x1c) = 0x9dabb8;
    func_637b00();
}
