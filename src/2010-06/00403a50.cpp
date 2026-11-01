// from server: 100% by auto
// roc 2010-06 00403a50  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403a50
//
// 00403a50  53                   push ebx
// 00403a51  55                   push ebp
// 00403a52  56                   push esi
// 00403a53  57                   push edi
// 00403a54  8bf9                 mov edi, ecx
// 00403a56  33f6                 xor esi, esi
// 00403a58  397708               cmp dword ptr [edi + 8], esi
// 00403a5b  7e1f                 jle 0x403a7c
// 00403a5d  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00403a61  8b2d84a39e00         mov ebp, dword ptr [0x9ea384]
// 00403a67  8b03                 mov eax, dword ptr [ebx]
// 00403a69  8b0f                 mov ecx, dword ptr [edi]
// 00403a6b  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00403a6e  50                   push eax
// 00403a6f  51                   push ecx
// 00403a70  ffd5                 call ebp
// 00403a72  85c0                 test eax, eax
// 00403a74  7410                 je 0x403a86
// 00403a76  46                   inc esi
// 00403a77  3b7708               cmp esi, dword ptr [edi + 8]
// 00403a7a  7ceb                 jl 0x403a67
// 00403a7c  5f                   pop edi
// 00403a7d  5e                   pop esi
// 00403a7e  5d                   pop ebp
// 00403a7f  83c8ff               or eax, 0xffffffff
// 00403a82  5b                   pop ebx
// 00403a83  c20400               ret 4
// 00403a86  5f                   pop edi
// 00403a87  8bc6                 mov eax, esi
// 00403a89  5e                   pop esi
// 00403a8a  5d                   pop ebp
// 00403a8b  5b                   pop ebx
// 00403a8c  c20400               ret 4
// library atl-9.0/atl.cpp (function ?FindKey@?$CSimpleMap@PADPA_WVCExpansionVectorEqualHelper@ATL@@@ATL@@QBEHABQAD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
