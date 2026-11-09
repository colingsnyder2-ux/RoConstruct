// from server: 100% by nuck16
// roc 2009-12 006fe270  unit: RBX::Humanoid  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fe270
//
// 006fe270  c701a4d69d00         mov dword ptr [ecx], 0x9dd6a4
// 006fe276  c741049cd69d00       mov dword ptr [ecx + 4], 0x9dd69c
// 006fe27d  c7411890d69d00       mov dword ptr [ecx + 0x18], 0x9dd690
// 006fe284  c7411c88d69d00       mov dword ptr [ecx + 0x1c], 0x9dd688
// 006fe28b  c7819400000080d69d00 mov dword ptr [ecx + 0x94], 0x9dd680
// 006fe295  e96698f3ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dd6a4;
    *(int *)((char *)this + 0x4) = 0x9dd69c;
    *(int *)((char *)this + 0x18) = 0x9dd690;
    *(int *)((char *)this + 0x1c) = 0x9dd688;
    *(int *)((char *)this + 0x94) = 0x9dd680;
    func_637b00();
}
