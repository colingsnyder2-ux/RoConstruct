// from server: 100% by nuck16
// roc 2009-12 006dfc70  unit: RBX::VSpecialShape::?$FactoryProduct  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006dfc70
//
// 006dfc70  c70174a49d00         mov dword ptr [ecx], 0x9da474
// 006dfc76  c7410468a49d00       mov dword ptr [ecx + 4], 0x9da468
// 006dfc7d  c741185ca49d00       mov dword ptr [ecx + 0x18], 0x9da45c
// 006dfc84  c7411c54a49d00       mov dword ptr [ecx + 0x1c], 0x9da454
// 006dfc8b  e9c0feffff           jmp 0x6dfb50

extern "C" void func_6dfb50();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9da474;
    *(int *)((char *)this + 0x4) = 0x9da468;
    *(int *)((char *)this + 0x18) = 0x9da45c;
    *(int *)((char *)this + 0x1c) = 0x9da454;
    func_6dfb50();
}
