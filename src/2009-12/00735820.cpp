// from server: 100% by nuck16
// roc 2009-12 00735820  unit: RBX::BodyForce  size: 62 bytes
//
// 00735820  c70124109e00         mov dword ptr [ecx], 0x9e1024
// 00735826  c7410418109e00       mov dword ptr [ecx + 4], 0x9e1018
// 0073582d  c741180c109e00       mov dword ptr [ecx + 0x18], 0x9e100c
// 00735834  c7411c04109e00       mov dword ptr [ecx + 0x1c], 0x9e1004
// 0073583b  c78194000000bc0f9e00 mov dword ptr [ecx + 0x94], 0x9e0fbc
// 00735845  c781b40000009c0f9e00 mov dword ptr [ecx + 0xb4], 0x9e0f9c
// 0073584f  c7812c010000800f9e00 mov dword ptr [ecx + 0x12c], 0x9e0f80
// 00735859  e982fcffff           jmp 0x7354e0

extern "C" void func_7354e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e1024;
    *(int *)((char *)this + 0x4) = 0x9e1018;
    *(int *)((char *)this + 0x18) = 0x9e100c;
    *(int *)((char *)this + 0x1c) = 0x9e1004;
    *(int *)((char *)this + 0x94) = 0x9e0fbc;
    *(int *)((char *)this + 0xb4) = 0x9e0f9c;
    *(int *)((char *)this + 0x12c) = 0x9e0f80;
    func_7354e0();
}
