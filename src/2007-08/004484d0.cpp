// from server: 100% by tester
// roc 2007-03 00447b50  unit: seg_00440000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00447b50
//
// 00447b50  85c0                 test eax, eax
// 00447b52  7501                 jne 0x447b55
// 00447b54  c3                   ret 
// 00447b55  8a08                 mov cl, byte ptr [eax]
// 00447b57  56                   push esi
// 00447b58  33f6                 xor esi, esi
// 00447b5a  84c9                 test cl, cl
// 00447b5c  7427                 je 0x447b85
// 00447b5e  57                   push edi
// 00447b5f  8b3d60ee7700         mov edi, dword ptr [0x77ee60]
// 00447b65  80f92e               cmp cl, 0x2e
// 00447b68  7409                 je 0x447b73
// 00447b6a  80f95c               cmp cl, 0x5c
// 00447b6d  7506                 jne 0x447b75
// 00447b6f  33f6                 xor esi, esi
// 00447b71  eb02                 jmp 0x447b75
// 00447b73  8bf0                 mov esi, eax
// 00447b75  50                   push eax
// 00447b76  ffd7                 call edi
// 00447b78  8a08                 mov cl, byte ptr [eax]
// 00447b7a  84c9                 test cl, cl
// 00447b7c  75e7                 jne 0x447b65
// 00447b7e  85f6                 test esi, esi
// 00447b80  5f                   pop edi
// 00447b81  7402                 je 0x447b85
// 00447b83  8bc6                 mov eax, esi
// 00447b85  5e                   pop esi
// 00447b86  c3                   ret 
// library atl-8.0/atl.cpp (function ?AtlFindExtension@ATL@@YAPADPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
