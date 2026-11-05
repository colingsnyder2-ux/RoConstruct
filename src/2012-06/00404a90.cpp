// from server: 100% by auto
// roc 2012-06 00404a90  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404a90
//
// 00404a90  53                   push ebx
// 00404a91  55                   push ebp
// 00404a92  56                   push esi
// 00404a93  57                   push edi
// 00404a94  8bf9                 mov edi, ecx
// 00404a96  33f6                 xor esi, esi
// 00404a98  397708               cmp dword ptr [edi + 8], esi
// 00404a9b  7e1f                 jle 0x404abc
// 00404a9d  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00404aa1  8b2da421b200         mov ebp, dword ptr [0xb221a4]
// 00404aa7  8b03                 mov eax, dword ptr [ebx]
// 00404aa9  8b0f                 mov ecx, dword ptr [edi]
// 00404aab  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00404aae  50                   push eax
// 00404aaf  51                   push ecx
// 00404ab0  ffd5                 call ebp
// 00404ab2  85c0                 test eax, eax
// 00404ab4  7410                 je 0x404ac6
// 00404ab6  46                   inc esi
// 00404ab7  3b7708               cmp esi, dword ptr [edi + 8]
// 00404aba  7ceb                 jl 0x404aa7
// 00404abc  5f                   pop edi
// 00404abd  5e                   pop esi
// 00404abe  5d                   pop ebp
// 00404abf  83c8ff               or eax, 0xffffffff
// 00404ac2  5b                   pop ebx
// 00404ac3  c20400               ret 4
// 00404ac6  5f                   pop edi
// 00404ac7  8bc6                 mov eax, esi
// 00404ac9  5e                   pop esi
// 00404aca  5d                   pop ebp
// 00404acb  5b                   pop ebx
// 00404acc  c20400               ret 4
// library atl-9.0/atl.cpp (function ?FindKey@?$CSimpleMap@PADPA_WVCExpansionVectorEqualHelper@ATL@@@ATL@@QBEHABQAD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
