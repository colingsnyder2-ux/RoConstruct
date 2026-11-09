// from server: 100% by auto
// roc 2007-03 00449320  unit: seg_00440000  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00449320
//
// 00449320  55                   push ebp
// 00449321  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00449325  85ed                 test ebp, ebp
// 00449327  7509                 jne 0x449332
// 00449329  b857000780           mov eax, 0x80070057
// 0044932e  5d                   pop ebp
// 0044932f  c20c00               ret 0xc
// 00449332  53                   push ebx
// 00449333  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00449336  56                   push esi
// 00449337  57                   push edi
// 00449338  33ff                 xor edi, edi
// 0044933a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044933d  734e                 jae 0x44938d
// 0044933f  90                   nop 
// 00449340  8b33                 mov esi, dword ptr [ebx]
// 00449342  85f6                 test esi, esi
// 00449344  743b                 je 0x449381
// 00449346  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044934a  85c0                 test eax, eax
// 0044934c  7410                 je 0x44935e
// 0044934e  8b0e                 mov ecx, dword ptr [esi]
// 00449350  51                   push ecx
// 00449351  50                   push eax
// 00449352  e8f927feff           call 0x42bb50
// 00449357  83c408               add esp, 8
// 0044935a  85c0                 test eax, eax
// 0044935c  7423                 je 0x449381
// 0044935e  8b561c               mov edx, dword ptr [esi + 0x1c]
// 00449361  6a00                 push 0
// 00449363  ffd2                 call edx
// 00449365  50                   push eax
// 00449366  8b06                 mov eax, dword ptr [esi]
// 00449368  50                   push eax
// 00449369  e862f6ffff           call 0x4489d0
// 0044936e  8bf8                 mov edi, eax
// 00449370  85ff                 test edi, edi
// 00449372  7c2d                 jl 0x4493a1
// 00449374  8b4e04               mov ecx, dword ptr [esi + 4]
// 00449377  6a00                 push 0
// 00449379  ffd1                 call ecx
// 0044937b  8bf8                 mov edi, eax
// 0044937d  85ff                 test edi, edi
// 0044937f  7c20                 jl 0x4493a1
// 00449381  83c304               add ebx, 4
// 00449384  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 00449387  72b7                 jb 0x449340
// 00449389  85ff                 test edi, edi
// 0044938b  7c14                 jl 0x4493a1
// 0044938d  837c241800           cmp dword ptr [esp + 0x18], 0
// 00449392  740d                 je 0x4493a1
// 00449394  8b5504               mov edx, dword ptr [ebp + 4]
// 00449397  6a00                 push 0
// 00449399  52                   push edx
// 0044939a  e811f4ffff           call 0x4487b0
// 0044939f  8bf8                 mov edi, eax
// 004493a1  8bc7                 mov eax, edi
// 004493a3  5f                   pop edi
// 004493a4  5e                   pop esi
// 004493a5  5b                   pop ebx
// 004493a6  5d                   pop ebp
// 004493a7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
