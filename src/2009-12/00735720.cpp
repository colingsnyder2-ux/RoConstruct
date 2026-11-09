// from server: 100% by nuck16
// roc 2009-12 00735720  unit: RBX::BodyForce  size: 62 bytes
//
// 00735720  c701440c9e00         mov dword ptr [ecx], 0x9e0c44
// 00735726  c74104380c9e00       mov dword ptr [ecx + 4], 0x9e0c38
// 0073572d  c741182c0c9e00       mov dword ptr [ecx + 0x18], 0x9e0c2c
// 00735734  c7411c240c9e00       mov dword ptr [ecx + 0x1c], 0x9e0c24
// 0073573b  c78194000000dc0b9e00 mov dword ptr [ecx + 0x94], 0x9e0bdc
// 00735745  c781b4000000bc0b9e00 mov dword ptr [ecx + 0xb4], 0x9e0bbc
// 0073574f  c7812c010000a00b9e00 mov dword ptr [ecx + 0x12c], 0x9e0ba0
// 00735759  e982fdffff           jmp 0x7354e0

extern "C" void func_7354e0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e0c44;
    *(int *)((char *)this + 0x4) = 0x9e0c38;
    *(int *)((char *)this + 0x18) = 0x9e0c2c;
    *(int *)((char *)this + 0x1c) = 0x9e0c24;
    *(int *)((char *)this + 0x94) = 0x9e0bdc;
    *(int *)((char *)this + 0xb4) = 0x9e0bbc;
    *(int *)((char *)this + 0x12c) = 0x9e0ba0;
    func_7354e0();
}
