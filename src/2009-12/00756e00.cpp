// from server: 100% by nuck16
// roc 2009-12 00756e00  unit: RBX::ScreenGui  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00756e00
//
// 00756e00  c7015c509e00         mov dword ptr [ecx], 0x9e505c
// 00756e06  c7410450509e00       mov dword ptr [ecx + 4], 0x9e5050
// 00756e0d  c7411844509e00       mov dword ptr [ecx + 0x18], 0x9e5044
// 00756e14  c7411c3c509e00       mov dword ptr [ecx + 0x1c], 0x9e503c
// 00756e1b  c781940000002c509e00 mov dword ptr [ecx + 0x94], 0x9e502c
// 00756e25  c7819800000014509e00 mov dword ptr [ecx + 0x98], 0x9e5014
// 00756e2f  e9fc0bffff           jmp 0x747a30

extern "C" void func_747a30();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e505c;
    *(int *)((char *)this + 0x4) = 0x9e5050;
    *(int *)((char *)this + 0x18) = 0x9e5044;
    *(int *)((char *)this + 0x1c) = 0x9e503c;
    *(int *)((char *)this + 0x94) = 0x9e502c;
    *(int *)((char *)this + 0x98) = 0x9e5014;
    func_747a30();
}
