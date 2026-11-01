// from server: 100% by auto
// roc 2010-06 0044d070  unit: CRobloxApp  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044d070
//
// 0044d070  85c0                 test eax, eax
// 0044d072  7501                 jne 0x44d075
// 0044d074  c3                   ret 
// 0044d075  8a08                 mov cl, byte ptr [eax]
// 0044d077  56                   push esi
// 0044d078  33f6                 xor esi, esi
// 0044d07a  84c9                 test cl, cl
// 0044d07c  7427                 je 0x44d0a5
// 0044d07e  57                   push edi
// 0044d07f  8b3d64ba9e00         mov edi, dword ptr [0x9eba64]
// 0044d085  80f92e               cmp cl, 0x2e
// 0044d088  7409                 je 0x44d093
// 0044d08a  80f95c               cmp cl, 0x5c
// 0044d08d  7506                 jne 0x44d095
// 0044d08f  33f6                 xor esi, esi
// 0044d091  eb02                 jmp 0x44d095
// 0044d093  8bf0                 mov esi, eax
// 0044d095  50                   push eax
// 0044d096  ffd7                 call edi
// 0044d098  8a08                 mov cl, byte ptr [eax]
// 0044d09a  84c9                 test cl, cl
// 0044d09c  75e7                 jne 0x44d085
// 0044d09e  5f                   pop edi
// 0044d09f  85f6                 test esi, esi
// 0044d0a1  7402                 je 0x44d0a5
// 0044d0a3  8bc6                 mov eax, esi
// 0044d0a5  5e                   pop esi
// 0044d0a6  c3                   ret 
// library atl-9.0/atl.cpp (function ?AtlFindExtension@ATL@@YAPADPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
