// from server: 100% by EspClaude
// roc 2009-06 0041cfb0  unit: CEnabledCmdUI  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cfb0
//
// 0041cfb0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0041cfb3  56                   push esi
// 0041cfb4  8b3590ee8900         mov esi, dword ptr [0x89ee90]
// 0041cfba  6a00                 push 0
// 0041cfbc  6a00                 push 0
// 0041cfbe  680f110000           push 0x110f
// 0041cfc3  50                   push eax
// 0041cfc4  ffd6                 call esi
// 0041cfc6  50                   push eax
// 0041cfc7  e836bd2f00           call 0x718d02
// 0041cfcc  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0041cfcf  6a00                 push 0
// 0041cfd1  6a20                 push 0x20
// 0041cfd3  68c5000000           push 0xc5
// 0041cfd8  51                   push ecx
// 0041cfd9  ffd6                 call esi
// 0041cfdb  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041cfdf  c70200000000         mov dword ptr [edx], 0
// 0041cfe5  5e                   pop esi
// 0041cfe6  c20800               ret 8
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
