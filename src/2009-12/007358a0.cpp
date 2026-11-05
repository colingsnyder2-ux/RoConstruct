// from server: 100% by nuck16
// roc 2009-12 007358a0  unit: RBX::BodyForce  size: 62 bytes
//
// 007358a0  c70114129e00         mov dword ptr [ecx], 0x9e1214
// 007358a6  c7410408129e00       mov dword ptr [ecx + 4], 0x9e1208
// 007358ad  c74118fc119e00       mov dword ptr [ecx + 0x18], 0x9e11fc
// 007358b4  c7411cf4119e00       mov dword ptr [ecx + 0x1c], 0x9e11f4
// 007358bb  c78194000000ac119e00 mov dword ptr [ecx + 0x94], 0x9e11ac
// 007358c5  c781b40000008c119e00 mov dword ptr [ecx + 0xb4], 0x9e118c
// 007358cf  c7812c01000070119e00 mov dword ptr [ecx + 0x12c], 0x9e1170
// 007358d9  e902fcffff           jmp 0x7354e0

extern "C" void func_7354e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e1214;
    *(int *)((char *)this + 0x4) = 0x9e1208;
    *(int *)((char *)this + 0x18) = 0x9e11fc;
    *(int *)((char *)this + 0x1c) = 0x9e11f4;
    *(int *)((char *)this + 0x94) = 0x9e11ac;
    *(int *)((char *)this + 0xb4) = 0x9e118c;
    *(int *)((char *)this + 0x12c) = 0x9e1170;
    func_7354e0();
}
