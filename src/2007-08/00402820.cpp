// from server: 100% by tester
// roc 2007-03 00402840  unit: seg_00400000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00402840
//
// 00402840  53                   push ebx
// 00402841  55                   push ebp
// 00402842  56                   push esi
// 00402843  57                   push edi
// 00402844  8bf9                 mov edi, ecx
// 00402846  33f6                 xor esi, esi
// 00402848  397708               cmp dword ptr [edi + 8], esi
// 0040284b  7e21                 jle 0x40286e
// 0040284d  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00402851  8b2db0d27700         mov ebp, dword ptr [0x77d2b0]
// 00402857  8b03                 mov eax, dword ptr [ebx]
// 00402859  8b0f                 mov ecx, dword ptr [edi]
// 0040285b  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0040285e  50                   push eax
// 0040285f  51                   push ecx
// 00402860  ffd5                 call ebp
// 00402862  85c0                 test eax, eax
// 00402864  7412                 je 0x402878
// 00402866  83c601               add esi, 1
// 00402869  3b7708               cmp esi, dword ptr [edi + 8]
// 0040286c  7ce9                 jl 0x402857
// 0040286e  5f                   pop edi
// 0040286f  5e                   pop esi
// 00402870  5d                   pop ebp
// 00402871  83c8ff               or eax, 0xffffffff
// 00402874  5b                   pop ebx
// 00402875  c20400               ret 4
// 00402878  5f                   pop edi
// 00402879  8bc6                 mov eax, esi
// 0040287b  5e                   pop esi
// 0040287c  5d                   pop ebp
// 0040287d  5b                   pop ebx
// 0040287e  c20400               ret 4
// library atl-8.0/atl.cpp (function ?FindKey@?$CSimpleMap@PADPA_WVCExpansionVectorEqualHelper@ATL@@@ATL@@QBEHABQAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
