// from server: 100% by auto
// roc 2008-06 004024e0  unit: std::bad_alloc  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004024e0
//
// 004024e0  53                   push ebx
// 004024e1  55                   push ebp
// 004024e2  56                   push esi
// 004024e3  57                   push edi
// 004024e4  8bf9                 mov edi, ecx
// 004024e6  33f6                 xor esi, esi
// 004024e8  397708               cmp dword ptr [edi + 8], esi
// 004024eb  7e1f                 jle 0x40250c
// 004024ed  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 004024f1  8b2db4218000         mov ebp, dword ptr [0x8021b4]
// 004024f7  8b03                 mov eax, dword ptr [ebx]
// 004024f9  8b0f                 mov ecx, dword ptr [edi]
// 004024fb  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 004024fe  50                   push eax
// 004024ff  51                   push ecx
// 00402500  ffd5                 call ebp
// 00402502  85c0                 test eax, eax
// 00402504  7410                 je 0x402516
// 00402506  46                   inc esi
// 00402507  3b7708               cmp esi, dword ptr [edi + 8]
// 0040250a  7ceb                 jl 0x4024f7
// 0040250c  5f                   pop edi
// 0040250d  5e                   pop esi
// 0040250e  5d                   pop ebp
// 0040250f  83c8ff               or eax, 0xffffffff
// 00402512  5b                   pop ebx
// 00402513  c20400               ret 4
// 00402516  5f                   pop edi
// 00402517  8bc6                 mov eax, esi
// 00402519  5e                   pop esi
// 0040251a  5d                   pop ebp
// 0040251b  5b                   pop ebx
// 0040251c  c20400               ret 4
// library atl-9.0/atl.cpp (function ?FindKey@?$CSimpleMap@PADPA_WVCExpansionVectorEqualHelper@ATL@@@ATL@@QBEHABQAD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
