// from server: 100% by nuck16
// roc 2009-12 00735860  unit: RBX::BodyForce  size: 62 bytes
//
// 00735860  c7011c119e00         mov dword ptr [ecx], 0x9e111c
// 00735866  c7410410119e00       mov dword ptr [ecx + 4], 0x9e1110
// 0073586d  c7411804119e00       mov dword ptr [ecx + 0x18], 0x9e1104
// 00735874  c7411cfc109e00       mov dword ptr [ecx + 0x1c], 0x9e10fc
// 0073587b  c78194000000b4109e00 mov dword ptr [ecx + 0x94], 0x9e10b4
// 00735885  c781b400000094109e00 mov dword ptr [ecx + 0xb4], 0x9e1094
// 0073588f  c7812c01000078109e00 mov dword ptr [ecx + 0x12c], 0x9e1078
// 00735899  e942fcffff           jmp 0x7354e0

extern "C" void func_7354e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e111c;
    *(int *)((char *)this + 0x4) = 0x9e1110;
    *(int *)((char *)this + 0x18) = 0x9e1104;
    *(int *)((char *)this + 0x1c) = 0x9e10fc;
    *(int *)((char *)this + 0x94) = 0x9e10b4;
    *(int *)((char *)this + 0xb4) = 0x9e1094;
    *(int *)((char *)this + 0x12c) = 0x9e1078;
    func_7354e0();
}
