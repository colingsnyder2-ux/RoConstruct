// from server: 100% by nuck16
// roc 2009-12 006c7260  unit: RBX::IStepped  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c7260
//
// 006c7260  c70174749d00         mov dword ptr [ecx], 0x9d7474
// 006c7266  c7410468749d00       mov dword ptr [ecx + 4], 0x9d7468
// 006c726d  c741185c749d00       mov dword ptr [ecx + 0x18], 0x9d745c
// 006c7274  c7411c54749d00       mov dword ptr [ecx + 0x1c], 0x9d7454
// 006c727b  e98008f7ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d7474;
    *(int *)((char *)this + 0x4) = 0x9d7468;
    *(int *)((char *)this + 0x18) = 0x9d745c;
    *(int *)((char *)this + 0x1c) = 0x9d7454;
    func_637b00();
}
