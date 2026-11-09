// from server: 100% by nuck16
// roc 2009-12 00715aa0  unit: RBX::JointInstance  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00715aa0
//
// 00715aa0  c701cceb9d00         mov dword ptr [ecx], 0x9debcc
// 00715aa6  c74104c0eb9d00       mov dword ptr [ecx + 4], 0x9debc0
// 00715aad  c74118b4eb9d00       mov dword ptr [ecx + 0x18], 0x9debb4
// 00715ab4  c7411caceb9d00       mov dword ptr [ecx + 0x1c], 0x9debac
// 00715abb  c7819400000094eb9d00 mov dword ptr [ecx + 0x94], 0x9deb94
// 00715ac5  e9c6feffff           jmp 0x715990

extern "C" void func_715990();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9debcc;
    *(int *)((char *)this + 0x4) = 0x9debc0;
    *(int *)((char *)this + 0x18) = 0x9debb4;
    *(int *)((char *)this + 0x1c) = 0x9debac;
    *(int *)((char *)this + 0x94) = 0x9deb94;
    func_715990();
}
