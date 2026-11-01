// from server: 100% by auto
// roc 2009-12 0044b0d0  unit: CRobloxControlColorSelector  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044b0d0
//
// 0044b0d0  85c0                 test eax, eax
// 0044b0d2  7501                 jne 0x44b0d5
// 0044b0d4  c3                   ret 
// 0044b0d5  8a08                 mov cl, byte ptr [eax]
// 0044b0d7  56                   push esi
// 0044b0d8  33f6                 xor esi, esi
// 0044b0da  84c9                 test cl, cl
// 0044b0dc  7427                 je 0x44b105
// 0044b0de  57                   push edi
// 0044b0df  8b3dd4cb9800         mov edi, dword ptr [0x98cbd4]
// 0044b0e5  80f92e               cmp cl, 0x2e
// 0044b0e8  7409                 je 0x44b0f3
// 0044b0ea  80f95c               cmp cl, 0x5c
// 0044b0ed  7506                 jne 0x44b0f5
// 0044b0ef  33f6                 xor esi, esi
// 0044b0f1  eb02                 jmp 0x44b0f5
// 0044b0f3  8bf0                 mov esi, eax
// 0044b0f5  50                   push eax
// 0044b0f6  ffd7                 call edi
// 0044b0f8  8a08                 mov cl, byte ptr [eax]
// 0044b0fa  84c9                 test cl, cl
// 0044b0fc  75e7                 jne 0x44b0e5
// 0044b0fe  5f                   pop edi
// 0044b0ff  85f6                 test esi, esi
// 0044b101  7402                 je 0x44b105
// 0044b103  8bc6                 mov eax, esi
// 0044b105  5e                   pop esi
// 0044b106  c3                   ret 
// library atl-9.0/atl.cpp (function ?AtlFindExtension@ATL@@YAPADPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
