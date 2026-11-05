// from server: 100% by nuck16
// roc 2009-12 00680c40  unit: RBX::P8Script::?$GetSetImpl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00680c40
//
// 00680c40  c7012c039d00         mov dword ptr [ecx], 0x9d032c
// 00680c46  c7410420039d00       mov dword ptr [ecx + 4], 0x9d0320
// 00680c4d  c7411814039d00       mov dword ptr [ecx + 0x18], 0x9d0314
// 00680c54  c7411c0c039d00       mov dword ptr [ecx + 0x1c], 0x9d030c
// 00680c5b  e9a06efbff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9d032c;
    *(int *)((char *)this + 0x4) = 0x9d0320;
    *(int *)((char *)this + 0x18) = 0x9d0314;
    *(int *)((char *)this + 0x1c) = 0x9d030c;
    func_637b00();
}
