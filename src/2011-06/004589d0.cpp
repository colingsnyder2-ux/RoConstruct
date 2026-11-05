// from server: 100% by auto
// roc 2011-06 004589d0  unit: CRobloxControlColorSelector  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004589d0
//
// 004589d0  85c0                 test eax, eax
// 004589d2  7501                 jne 0x4589d5
// 004589d4  c3                   ret 
// 004589d5  8a08                 mov cl, byte ptr [eax]
// 004589d7  56                   push esi
// 004589d8  33f6                 xor esi, esi
// 004589da  84c9                 test cl, cl
// 004589dc  7427                 je 0x458a05
// 004589de  57                   push edi
// 004589df  8b3dd419a400         mov edi, dword ptr [0xa419d4]
// 004589e5  80f92e               cmp cl, 0x2e
// 004589e8  7409                 je 0x4589f3
// 004589ea  80f95c               cmp cl, 0x5c
// 004589ed  7506                 jne 0x4589f5
// 004589ef  33f6                 xor esi, esi
// 004589f1  eb02                 jmp 0x4589f5
// 004589f3  8bf0                 mov esi, eax
// 004589f5  50                   push eax
// 004589f6  ffd7                 call edi
// 004589f8  8a08                 mov cl, byte ptr [eax]
// 004589fa  84c9                 test cl, cl
// 004589fc  75e7                 jne 0x4589e5
// 004589fe  5f                   pop edi
// 004589ff  85f6                 test esi, esi
// 00458a01  7402                 je 0x458a05
// 00458a03  8bc6                 mov eax, esi
// 00458a05  5e                   pop esi
// 00458a06  c3                   ret 
// library atl-9.0/atl.cpp (function ?AtlFindExtension@ATL@@YAPADPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
