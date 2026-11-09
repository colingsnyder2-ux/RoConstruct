// from server: 100% by nuck16
// roc 2009-12 006fbf50  unit: G3D::Win32Window  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fbf50
//
// 006fbf50  c70154ce9d00         mov dword ptr [ecx], 0x9dce54
// 006fbf56  c741044cce9d00       mov dword ptr [ecx + 4], 0x9dce4c
// 006fbf5d  c7411840ce9d00       mov dword ptr [ecx + 0x18], 0x9dce40
// 006fbf64  c7411c38ce9d00       mov dword ptr [ecx + 0x1c], 0x9dce38
// 006fbf6b  e990bbf3ff           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dce54;
    *(int *)((char *)this + 0x4) = 0x9dce4c;
    *(int *)((char *)this + 0x18) = 0x9dce40;
    *(int *)((char *)this + 0x1c) = 0x9dce38;
    func_637b00();
}
