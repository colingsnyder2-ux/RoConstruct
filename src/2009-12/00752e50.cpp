// from server: 100% by nuck16
// roc 2009-12 00752e50  unit: RBX::VSurfaceSelection::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00752e50
//
// 00752e50  c701d4459e00         mov dword ptr [ecx], 0x9e45d4
// 00752e56  c74104c8459e00       mov dword ptr [ecx + 4], 0x9e45c8
// 00752e5d  c74118bc459e00       mov dword ptr [ecx + 0x18], 0x9e45bc
// 00752e64  c7411cb4459e00       mov dword ptr [ecx + 0x1c], 0x9e45b4
// 00752e6b  c78194000000a4459e00 mov dword ptr [ecx + 0x94], 0x9e45a4
// 00752e75  c781980000008c459e00 mov dword ptr [ecx + 0x98], 0x9e458c
// 00752e7f  e9fc960000           jmp 0x75c580

extern "C" void func_75c580();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e45d4;
    *(int *)((char *)this + 0x4) = 0x9e45c8;
    *(int *)((char *)this + 0x18) = 0x9e45bc;
    *(int *)((char *)this + 0x1c) = 0x9e45b4;
    *(int *)((char *)this + 0x94) = 0x9e45a4;
    *(int *)((char *)this + 0x98) = 0x9e458c;
    func_75c580();
}
