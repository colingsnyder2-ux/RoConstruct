// from server: 100% by nuck16
// roc 2009-12 007357e0  unit: RBX::BodyForce  size: 62 bytes
//
// 007357e0  c7012c0f9e00         mov dword ptr [ecx], 0x9e0f2c
// 007357e6  c74104200f9e00       mov dword ptr [ecx + 4], 0x9e0f20
// 007357ed  c74118140f9e00       mov dword ptr [ecx + 0x18], 0x9e0f14
// 007357f4  c7411c0c0f9e00       mov dword ptr [ecx + 0x1c], 0x9e0f0c
// 007357fb  c78194000000c40e9e00 mov dword ptr [ecx + 0x94], 0x9e0ec4
// 00735805  c781b4000000a40e9e00 mov dword ptr [ecx + 0xb4], 0x9e0ea4
// 0073580f  c7812c010000880e9e00 mov dword ptr [ecx + 0x12c], 0x9e0e88
// 00735819  e9c2fcffff           jmp 0x7354e0

extern "C" void func_7354e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e0f2c;
    *(int *)((char *)this + 0x4) = 0x9e0f20;
    *(int *)((char *)this + 0x18) = 0x9e0f14;
    *(int *)((char *)this + 0x1c) = 0x9e0f0c;
    *(int *)((char *)this + 0x94) = 0x9e0ec4;
    *(int *)((char *)this + 0xb4) = 0x9e0ea4;
    *(int *)((char *)this + 0x12c) = 0x9e0e88;
    func_7354e0();
}
