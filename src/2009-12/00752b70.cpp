// from server: 100% by nuck16
// roc 2009-12 00752b70  unit: RBX::VSelectionBox::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00752b70
//
// 00752b70  c70174449e00         mov dword ptr [ecx], 0x9e4474
// 00752b76  c7410468449e00       mov dword ptr [ecx + 4], 0x9e4468
// 00752b7d  c741185c449e00       mov dword ptr [ecx + 0x18], 0x9e445c
// 00752b84  c7411c54449e00       mov dword ptr [ecx + 0x1c], 0x9e4454
// 00752b8b  c7819400000044449e00 mov dword ptr [ecx + 0x94], 0x9e4444
// 00752b95  c781980000002c449e00 mov dword ptr [ecx + 0x98], 0x9e442c
// 00752b9f  e9dc990000           jmp 0x75c580

extern "C" void func_75c580();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e4474;
    *(int *)((char *)this + 0x4) = 0x9e4468;
    *(int *)((char *)this + 0x18) = 0x9e445c;
    *(int *)((char *)this + 0x1c) = 0x9e4454;
    *(int *)((char *)this + 0x94) = 0x9e4444;
    *(int *)((char *)this + 0x98) = 0x9e442c;
    func_75c580();
}
