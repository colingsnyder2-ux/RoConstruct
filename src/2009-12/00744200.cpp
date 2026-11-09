// from server: 100% by nuck16
// roc 2009-12 00744200  unit: RBX::Flag  size: 72 bytes
//
// 00744200  c7016c319e00         mov dword ptr [ecx], 0x9e316c
// 00744206  c7410460319e00       mov dword ptr [ecx + 4], 0x9e3160
// 0074420d  c7411854319e00       mov dword ptr [ecx + 0x18], 0x9e3154
// 00744214  c7411c4c319e00       mov dword ptr [ecx + 0x1c], 0x9e314c
// 0074421b  c7819400000044319e00 mov dword ptr [ecx + 0x94], 0x9e3144
// 00744225  c781140100003c319e00 mov dword ptr [ecx + 0x114], 0x9e313c
// 0074422f  c7812001000024319e00 mov dword ptr [ecx + 0x120], 0x9e3124
// 00744239  c781300100001c319e00 mov dword ptr [ecx + 0x130], 0x9e311c
// 00744243  e9980bf5ff           jmp 0x694de0

extern "C" void func_694de0();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e316c;
    *(int *)((char *)this + 0x4) = 0x9e3160;
    *(int *)((char *)this + 0x18) = 0x9e3154;
    *(int *)((char *)this + 0x1c) = 0x9e314c;
    *(int *)((char *)this + 0x94) = 0x9e3144;
    *(int *)((char *)this + 0x114) = 0x9e313c;
    *(int *)((char *)this + 0x120) = 0x9e3124;
    *(int *)((char *)this + 0x130) = 0x9e311c;
    func_694de0();
}
