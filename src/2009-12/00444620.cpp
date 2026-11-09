// from server: 100% by nuck16
// roc 2009-12 00444620  unit: RBX::P8CRenderSettings::?$GetSetImpl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00444620
//
// 00444620  c7011ca29a00         mov dword ptr [ecx], 0x9aa21c
// 00444626  c7410410a29a00       mov dword ptr [ecx + 4], 0x9aa210
// 0044462d  c7411804a29a00       mov dword ptr [ecx + 0x18], 0x9aa204
// 00444634  c7411cfca19a00       mov dword ptr [ecx + 0x1c], 0x9aa1fc
// 0044463b  e9c0341f00           jmp 0x637b00

extern "C" void func_637b00();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9aa21c;
    *(int *)((char *)this + 0x4) = 0x9aa210;
    *(int *)((char *)this + 0x18) = 0x9aa204;
    *(int *)((char *)this + 0x1c) = 0x9aa1fc;
    func_637b00();
}
