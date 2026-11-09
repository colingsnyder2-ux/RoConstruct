// from server: 100% by nuck16
// roc 2009-12 00758530  unit: RBX::VImageLabel::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00758530
//
// 00758530  c7017c589e00         mov dword ptr [ecx], 0x9e587c
// 00758536  c7410470589e00       mov dword ptr [ecx + 4], 0x9e5870
// 0075853d  c7411864589e00       mov dword ptr [ecx + 0x18], 0x9e5864
// 00758544  c7411c5c589e00       mov dword ptr [ecx + 0x1c], 0x9e585c
// 0075854b  c781940000004c589e00 mov dword ptr [ecx + 0x94], 0x9e584c
// 00758555  c7819800000034589e00 mov dword ptr [ecx + 0x98], 0x9e5834
// 0075855f  e92cf1ffff           jmp 0x757690

extern "C" void func_757690();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e587c;
    *(int *)((char *)this + 0x4) = 0x9e5870;
    *(int *)((char *)this + 0x18) = 0x9e5864;
    *(int *)((char *)this + 0x1c) = 0x9e585c;
    *(int *)((char *)this + 0x94) = 0x9e584c;
    *(int *)((char *)this + 0x98) = 0x9e5834;
    func_757690();
}
