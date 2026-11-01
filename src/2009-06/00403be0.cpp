// from server: 100% by auto
// roc 2009-06 00403be0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403be0
//
// 00403be0  53                   push ebx
// 00403be1  55                   push ebp
// 00403be2  56                   push esi
// 00403be3  57                   push edi
// 00403be4  8bf9                 mov edi, ecx
// 00403be6  33f6                 xor esi, esi
// 00403be8  397708               cmp dword ptr [edi + 8], esi
// 00403beb  7e1f                 jle 0x403c0c
// 00403bed  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00403bf1  8b2ddce18900         mov ebp, dword ptr [0x89e1dc]
// 00403bf7  8b03                 mov eax, dword ptr [ebx]
// 00403bf9  8b0f                 mov ecx, dword ptr [edi]
// 00403bfb  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00403bfe  50                   push eax
// 00403bff  51                   push ecx
// 00403c00  ffd5                 call ebp
// 00403c02  85c0                 test eax, eax
// 00403c04  7410                 je 0x403c16
// 00403c06  46                   inc esi
// 00403c07  3b7708               cmp esi, dword ptr [edi + 8]
// 00403c0a  7ceb                 jl 0x403bf7
// 00403c0c  5f                   pop edi
// 00403c0d  5e                   pop esi
// 00403c0e  5d                   pop ebp
// 00403c0f  83c8ff               or eax, 0xffffffff
// 00403c12  5b                   pop ebx
// 00403c13  c20400               ret 4
// 00403c16  5f                   pop edi
// 00403c17  8bc6                 mov eax, esi
// 00403c19  5e                   pop esi
// 00403c1a  5d                   pop ebp
// 00403c1b  5b                   pop ebx
// 00403c1c  c20400               ret 4
// library atl-9.0/atl.cpp (function ?FindKey@?$CSimpleMap@PADPA_WVCExpansionVectorEqualHelper@ATL@@@ATL@@QBEHABQAD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
