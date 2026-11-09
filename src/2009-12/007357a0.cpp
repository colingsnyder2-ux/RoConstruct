// from server: 100% by nuck16
// roc 2009-12 007357a0  unit: RBX::BodyForce  size: 62 bytes
//
// 007357a0  c701340e9e00         mov dword ptr [ecx], 0x9e0e34
// 007357a6  c74104280e9e00       mov dword ptr [ecx + 4], 0x9e0e28
// 007357ad  c741181c0e9e00       mov dword ptr [ecx + 0x18], 0x9e0e1c
// 007357b4  c7411c140e9e00       mov dword ptr [ecx + 0x1c], 0x9e0e14
// 007357bb  c78194000000cc0d9e00 mov dword ptr [ecx + 0x94], 0x9e0dcc
// 007357c5  c781b4000000ac0d9e00 mov dword ptr [ecx + 0xb4], 0x9e0dac
// 007357cf  c7812c010000900d9e00 mov dword ptr [ecx + 0x12c], 0x9e0d90
// 007357d9  e902fdffff           jmp 0x7354e0

extern "C" void func_7354e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e0e34;
    *(int *)((char *)this + 0x4) = 0x9e0e28;
    *(int *)((char *)this + 0x18) = 0x9e0e1c;
    *(int *)((char *)this + 0x1c) = 0x9e0e14;
    *(int *)((char *)this + 0x94) = 0x9e0dcc;
    *(int *)((char *)this + 0xb4) = 0x9e0dac;
    *(int *)((char *)this + 0x12c) = 0x9e0d90;
    func_7354e0();
}
