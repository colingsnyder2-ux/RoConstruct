// from server: 100% by auto
// roc 2008-06 00449f10  unit: CIDEDocManager  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00449f10
//
// 00449f10  85c0                 test eax, eax
// 00449f12  7501                 jne 0x449f15
// 00449f14  c3                   ret 
// 00449f15  8a08                 mov cl, byte ptr [eax]
// 00449f17  56                   push esi
// 00449f18  33f6                 xor esi, esi
// 00449f1a  84c9                 test cl, cl
// 00449f1c  7427                 je 0x449f45
// 00449f1e  57                   push edi
// 00449f1f  8b3d2c2e8000         mov edi, dword ptr [0x802e2c]
// 00449f25  80f92e               cmp cl, 0x2e
// 00449f28  7409                 je 0x449f33
// 00449f2a  80f95c               cmp cl, 0x5c
// 00449f2d  7506                 jne 0x449f35
// 00449f2f  33f6                 xor esi, esi
// 00449f31  eb02                 jmp 0x449f35
// 00449f33  8bf0                 mov esi, eax
// 00449f35  50                   push eax
// 00449f36  ffd7                 call edi
// 00449f38  8a08                 mov cl, byte ptr [eax]
// 00449f3a  84c9                 test cl, cl
// 00449f3c  75e7                 jne 0x449f25
// 00449f3e  5f                   pop edi
// 00449f3f  85f6                 test esi, esi
// 00449f41  7402                 je 0x449f45
// 00449f43  8bc6                 mov eax, esi
// 00449f45  5e                   pop esi
// 00449f46  c3                   ret 
// library atl-9.0/atl.cpp (function ?AtlFindExtension@ATL@@YAPADPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
