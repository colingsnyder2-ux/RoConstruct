// from server: 100% by nuck16
// roc 2009-12 00525360  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 42 bytes
//
// 00525360  c7019cbb9b00         mov dword ptr [ecx], 0x9bbb9c
// 00525366  c7410490bb9b00       mov dword ptr [ecx + 4], 0x9bbb90
// 0052536d  c7411884bb9b00       mov dword ptr [ecx + 0x18], 0x9bbb84
// 00525374  c7411c7cbb9b00       mov dword ptr [ecx + 0x1c], 0x9bbb7c
// 0052537b  c781940000004cbb9b00 mov dword ptr [ecx + 0x94], 0x9bbb4c
// 00525385  e9a6af0200           jmp 0x550330

extern "C" void func_550330();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9bbb9c;
    *(int *)((char *)this + 0x4) = 0x9bbb90;
    *(int *)((char *)this + 0x18) = 0x9bbb84;
    *(int *)((char *)this + 0x1c) = 0x9bbb7c;
    *(int *)((char *)this + 0x94) = 0x9bbb4c;
    func_550330();
}
