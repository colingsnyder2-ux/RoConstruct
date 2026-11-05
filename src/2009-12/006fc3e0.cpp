// from server: 100% by nuck16
// roc 2009-12 006fc3e0  unit: RBX::VStarterGuiService::?$FactoryProduct  size: 62 bytes
//
// 006fc3e0  c70104cf9d00         mov dword ptr [ecx], 0x9dcf04
// 006fc3e6  c74104f8ce9d00       mov dword ptr [ecx + 4], 0x9dcef8
// 006fc3ed  c74118ecce9d00       mov dword ptr [ecx + 0x18], 0x9dceec
// 006fc3f4  c7411ce4ce9d00       mov dword ptr [ecx + 0x1c], 0x9dcee4
// 006fc3fb  c78194000000dcce9d00 mov dword ptr [ecx + 0x94], 0x9dcedc
// 006fc405  c78198000000c4ce9d00 mov dword ptr [ecx + 0x98], 0x9dcec4
// 006fc40f  c781a8000000bcce9d00 mov dword ptr [ecx + 0xa8], 0x9dcebc
// 006fc419  e9f2fcffff           jmp 0x6fc110

extern "C" void func_6fc110();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dcf04;
    *(int *)((char *)this + 0x4) = 0x9dcef8;
    *(int *)((char *)this + 0x18) = 0x9dceec;
    *(int *)((char *)this + 0x1c) = 0x9dcee4;
    *(int *)((char *)this + 0x94) = 0x9dcedc;
    *(int *)((char *)this + 0x98) = 0x9dcec4;
    *(int *)((char *)this + 0xa8) = 0x9dcebc;
    func_6fc110();
}
