// from server: 100% by Xemicl
// roc 2012-06 00a819d1  unit: seg_00a80000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a819d1
//
// 00a819d1  8bff                 mov edi, edi
// 00a819d3  55                   push ebp
// 00a819d4  8bec                 mov ebp, esp
// 00a819d6  e897f9ffff           call 0xa81372
// 00a819db  85c0                 test eax, eax
// 00a819dd  740c                 je 0xa819eb
// 00a819df  b87d18a800           mov eax, 0xa8187d
// 00a819e4  a3bcede000           mov dword ptr [0xe0edbc], eax
// 00a819e9  eb0f                 jmp 0xa819fa
// 00a819eb  c705bcede0006716a800 mov dword ptr [0xe0edbc], 0xa81667
// 00a819f5  b89117a800           mov eax, 0xa81791
// 00a819fa  a3c0ede000           mov dword ptr [0xe0edc0], eax
// 00a819ff  5d                   pop ebp
// 00a81a00  ffe0                 jmp eax
// copied from an identical function in another client (function _dispatch_820ad0@4)

// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD /Oy- /hotpatch
typedef int (__stdcall *Fn)(int);
extern "C" int __cdecl check_820471();
extern "C" int __stdcall impl_82097c(int);
extern "C" int __stdcall impl_820766(int);
extern "C" int __stdcall impl_820890(int);
extern Fn g_a3183c;
extern Fn g_a31840;
extern "C" int __stdcall dispatch_820ad0(int a)
{
    if (check_820471()) {
        g_a3183c = impl_82097c;
        g_a31840 = impl_82097c;
    } else {
        g_a3183c = impl_820766;
        g_a31840 = impl_820890;
    }
    return g_a31840(a);
}