// from server: 100% by Xemicl
// roc 2012-06 0042a9b0  unit: CEnabledCmdUI  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a9b0
//
// 0042a9b0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0042a9b3  56                   push esi
// 0042a9b4  8b35043cb200         mov esi, dword ptr [0xb23c04]
// 0042a9ba  6a00                 push 0
// 0042a9bc  6a00                 push 0
// 0042a9be  680f110000           push 0x110f
// 0042a9c3  50                   push eax
// 0042a9c4  ffd6                 call esi
// 0042a9c6  50                   push eax
// 0042a9c7  e89a7c5500           call 0x982666
// 0042a9cc  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0042a9cf  6a00                 push 0
// 0042a9d1  6a20                 push 0x20
// 0042a9d3  68c5000000           push 0xc5
// 0042a9d8  51                   push ecx
// 0042a9d9  ffd6                 call esi
// 0042a9db  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0042a9df  c70200000000         mov dword ptr [edx], 0
// 0042a9e5  5e                   pop esi
// 0042a9e6  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX00007f@@QAEXPAXPAJ@Z)

namespace ns_ROCX00007f {
struct S {
    char padding[32];
    void* handle;
    void f(void* unused, long* result);
};

extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);
extern "C" S* __stdcall FromHandle(void*);

void S::f(void* unused, long* result)
{
    long (__stdcall *send)(void*, unsigned int, unsigned int, long) = SendMessageA;
    S* control = FromHandle((void*)send(handle, 0x110F, 0, 0));
    send(control->handle, 0xC5, 0x20, 0);
    *result = 0;
}
}