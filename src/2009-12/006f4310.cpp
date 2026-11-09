// from server: 100% by nuck16
// roc 2009-12 006f4310  unit: RBX::VBackpack::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f4310
//
// 006f4310  c70134c79d00         mov dword ptr [ecx], 0x9dc734
// 006f4316  c741042cc79d00       mov dword ptr [ecx + 4], 0x9dc72c
// 006f431d  c7411820c79d00       mov dword ptr [ecx + 0x18], 0x9dc720
// 006f4324  c7411c18c79d00       mov dword ptr [ecx + 0x1c], 0x9dc718
// 006f432b  c7819400000010c79d00 mov dword ptr [ecx + 0x94], 0x9dc710
// 006f4335  e936b3d1ff           jmp 0x40f670

extern "C" void func_40f670();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9dc734;
    *(int *)((char *)this + 0x4) = 0x9dc72c;
    *(int *)((char *)this + 0x18) = 0x9dc720;
    *(int *)((char *)this + 0x1c) = 0x9dc718;
    *(int *)((char *)this + 0x94) = 0x9dc710;
    func_40f670();
}
