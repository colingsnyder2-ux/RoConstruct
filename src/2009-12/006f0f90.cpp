// from server: 100% by nuck16
// roc 2009-12 006f0f90  unit: RBX::P8Tool::?$GetSetImpl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f0f90
//
// 006f0f90  c70134b69d00         mov dword ptr [ecx], 0x9db634
// 006f0f96  c7410428b69d00       mov dword ptr [ecx + 4], 0x9db628
// 006f0f9d  c741181cb69d00       mov dword ptr [ecx + 0x18], 0x9db61c
// 006f0fa4  c7411c14b69d00       mov dword ptr [ecx + 0x1c], 0x9db614
// 006f0fab  e9506bf4ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9db634;
    *(int *)((char *)this + 0x4) = 0x9db628;
    *(int *)((char *)this + 0x18) = 0x9db61c;
    *(int *)((char *)this + 0x1c) = 0x9db614;
    func_637b00();
}
