// from server: 100% by colin
// from server: 86% by king_originala
// roc 2008-06 00422f70  unit: CRobloxTreeCtrl  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00422f70
//
// 00422f70  53                   push ebx
// 00422f71  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00422f75  56                   push esi
// 00422f76  8bf1                 mov esi, ecx
// 00422f78  83fb71               cmp ebx, 0x71
// 00422f7b  752b                 jne 0x422fa8
// 00422f7d  8b4620               mov eax, dword ptr [esi + 0x20]
// 00422f80  57                   push edi
// 00422f81  8b3d142e8000         mov edi, dword ptr [0x802e14]
// 00422f87  6a00                 push 0
// 00422f89  6a09                 push 9
// 00422f8b  680a110000           push 0x110a
// 00422f90  50                   push eax
// 00422f91  ffd7                 call edi
// 00422f93  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00422f96  50                   push eax
// 00422f97  6a00                 push 0
// 00422f99  680e110000           push 0x110e
// 00422f9e  51                   push ecx
// 00422f9f  ffd7                 call edi
// 00422fa1  50                   push eax
// 00422fa2  e837dc2700           call 0x6a0bde
// 00422fa7  5f                   pop edi
// 00422fa8  8b542414             mov edx, dword ptr [esp + 0x14]
// 00422fac  8b442410             mov eax, dword ptr [esp + 0x10]
// 00422fb0  52                   push edx
// 00422fb1  50                   push eax
// 00422fb2  53                   push ebx
// 00422fb3  8d4e54               lea ecx, [esi + 0x54]
// 00422fb6  e855b62b00           call 0x6de610
// 00422fbb  5e                   pop esi
// 00422fbc  5b                   pop ebx
// 00422fbd  c20c00               ret 0xc
#include <intrin.h>
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

extern "C" void __stdcall func_006a0bde(long);

struct Handler
{
    void func_006de610(unsigned int, unsigned int, unsigned int);
};

struct CRobloxTreeCtrl
{
    char padding0[0x20];
    void* window;
    char padding1[0x30];
    Handler handler;

    void func_00422f70(unsigned int, unsigned int, unsigned int);
};

void CRobloxTreeCtrl::func_00422f70(unsigned int key, unsigned int repeat, unsigned int flags)
{
    if (key == 0x71)
    {
        long item = SendMessageA(window, 0x110a, 9, 0);
        func_006a0bde(SendMessageA(window, 0x110e, 0, item));
    }
    handler.func_006de610(key, repeat, flags);
}
