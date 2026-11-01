// from server: 100% by auto
// roc 2011-06 004042f0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004042f0
//
// 004042f0  53                   push ebx
// 004042f1  55                   push ebp
// 004042f2  56                   push esi
// 004042f3  57                   push edi
// 004042f4  8bf9                 mov edi, ecx
// 004042f6  33f6                 xor esi, esi
// 004042f8  397708               cmp dword ptr [edi + 8], esi
// 004042fb  7e1f                 jle 0x40431c
// 004042fd  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00404301  8b2d5403a400         mov ebp, dword ptr [0xa40354]
// 00404307  8b03                 mov eax, dword ptr [ebx]
// 00404309  8b0f                 mov ecx, dword ptr [edi]
// 0040430b  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0040430e  50                   push eax
// 0040430f  51                   push ecx
// 00404310  ffd5                 call ebp
// 00404312  85c0                 test eax, eax
// 00404314  7410                 je 0x404326
// 00404316  46                   inc esi
// 00404317  3b7708               cmp esi, dword ptr [edi + 8]
// 0040431a  7ceb                 jl 0x404307
// 0040431c  5f                   pop edi
// 0040431d  5e                   pop esi
// 0040431e  5d                   pop ebp
// 0040431f  83c8ff               or eax, 0xffffffff
// 00404322  5b                   pop ebx
// 00404323  c20400               ret 4
// 00404326  5f                   pop edi
// 00404327  8bc6                 mov eax, esi
// 00404329  5e                   pop esi
// 0040432a  5d                   pop ebp
// 0040432b  5b                   pop ebx
// 0040432c  c20400               ret 4
// library atl-9.0/atl.cpp (function ?FindKey@?$CSimpleMap@PADPA_WVCExpansionVectorEqualHelper@ATL@@@ATL@@QBEHABQAD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
