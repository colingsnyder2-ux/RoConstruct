// from server: 100% by nuck16
// roc 2009-12 006fe2a0  unit: RBX::Humanoid  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fe2a0
//
// 006fe2a0  c7011cd79d00         mov dword ptr [ecx], 0x9dd71c
// 006fe2a6  c7410414d79d00       mov dword ptr [ecx + 4], 0x9dd714
// 006fe2ad  c7411808d79d00       mov dword ptr [ecx + 0x18], 0x9dd708
// 006fe2b4  c7411c00d79d00       mov dword ptr [ecx + 0x1c], 0x9dd700
// 006fe2bb  c78194000000f8d69d00 mov dword ptr [ecx + 0x94], 0x9dd6f8
// 006fe2c5  e93698f3ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dd71c;
    *(int *)((char *)this + 0x4) = 0x9dd714;
    *(int *)((char *)this + 0x18) = 0x9dd708;
    *(int *)((char *)this + 0x1c) = 0x9dd700;
    *(int *)((char *)this + 0x94) = 0x9dd6f8;
    func_637b00();
}
