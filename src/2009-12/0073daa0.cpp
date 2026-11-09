// from server: 100% by nuck16
// roc 2009-12 0073daa0  unit: G3D::Win32Window  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073daa0
//
// 0073daa0  c701ec229e00         mov dword ptr [ecx], 0x9e22ec
// 0073daa6  c74104e0229e00       mov dword ptr [ecx + 4], 0x9e22e0
// 0073daad  c74118d4229e00       mov dword ptr [ecx + 0x18], 0x9e22d4
// 0073dab4  c7411ccc229e00       mov dword ptr [ecx + 0x1c], 0x9e22cc
// 0073dabb  e940a0efff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e22ec;
    *(int *)((char *)this + 0x4) = 0x9e22e0;
    *(int *)((char *)this + 0x18) = 0x9e22d4;
    *(int *)((char *)this + 0x1c) = 0x9e22cc;
    func_637b00();
}
