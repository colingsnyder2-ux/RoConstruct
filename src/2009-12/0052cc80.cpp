// from server: 100% by nuck16
// roc 2009-12 0052cc80  unit: RBX::VHint::?$FactoryProduct  size: 42 bytes
//
// 0052cc80  c70174c99b00         mov dword ptr [ecx], 0x9bc974
// 0052cc86  c741046cc99b00       mov dword ptr [ecx + 4], 0x9bc96c
// 0052cc8d  c7411860c99b00       mov dword ptr [ecx + 0x18], 0x9bc960
// 0052cc94  c7411c58c99b00       mov dword ptr [ecx + 0x1c], 0x9bc958
// 0052cc9b  c7819400000040c99b00 mov dword ptr [ecx + 0x94], 0x9bc940
// 0052cca5  e986feffff           jmp 0x52cb30

extern "C" void func_52cb30();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9bc974;
    *(int *)((char *)this + 0x4) = 0x9bc96c;
    *(int *)((char *)this + 0x18) = 0x9bc960;
    *(int *)((char *)this + 0x1c) = 0x9bc958;
    *(int *)((char *)this + 0x94) = 0x9bc940;
    func_52cb30();
}
