// from server: 100% by auto
// roc 2007-03 005f8540  unit: seg_005f0000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f8540
//
// 005f8540  53                   push ebx
// 005f8541  8bc2                 mov eax, edx
// 005f8543  57                   push edi
// 005f8544  8b7e08               mov edi, dword ptr [esi + 8]
// 005f8547  8d5801               lea ebx, [eax + 1]
// 005f854a  8d9b00000000         lea ebx, [ebx]
// 005f8550  8a08                 mov cl, byte ptr [eax]
// 005f8552  83c001               add eax, 1
// 005f8555  84c9                 test cl, cl
// 005f8557  75f7                 jne 0x5f8550
// 005f8559  2bc3                 sub eax, ebx
// 005f855b  50                   push eax
// 005f855c  52                   push edx
// 005f855d  56                   push esi
// 005f855e  e8bd410000           call 0x5fc720
// 005f8563  8907                 mov dword ptr [edi], eax
// 005f8565  c7470804000000       mov dword ptr [edi + 8], 4
// 005f856c  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005f856f  2b4608               sub eax, dword ptr [esi + 8]
// 005f8572  bf10000000           mov edi, 0x10
// 005f8577  83c40c               add esp, 0xc
// 005f857a  3bc7                 cmp eax, edi
// 005f857c  7f0b                 jg 0x5f8589
// 005f857e  6a01                 push 1
// 005f8580  56                   push esi
// 005f8581  e86a77fcff           call 0x5bfcf0
// 005f8586  83c408               add esp, 8
// 005f8589  017e08               add dword ptr [esi + 8], edi
// 005f858c  5f                   pop edi
// 005f858d  5b                   pop ebx
// 005f858e  c3                   ret 
// library lua-5.1.1/lobject.c (function _pushstr)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lobject.c
