// from server: 100% by nuck16
// roc 2009-12 00700790  unit: RBX::VTimerService::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00700790
//
// 00700790  c70164dd9d00         mov dword ptr [ecx], 0x9ddd64
// 00700796  c7410458dd9d00       mov dword ptr [ecx + 4], 0x9ddd58
// 0070079d  c741184cdd9d00       mov dword ptr [ecx + 0x18], 0x9ddd4c
// 007007a4  c7411c44dd9d00       mov dword ptr [ecx + 0x1c], 0x9ddd44
// 007007ab  e95073f3ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9ddd64;
    *(int *)((char *)this + 0x4) = 0x9ddd58;
    *(int *)((char *)this + 0x18) = 0x9ddd4c;
    *(int *)((char *)this + 0x1c) = 0x9ddd44;
    func_637b00();
}
