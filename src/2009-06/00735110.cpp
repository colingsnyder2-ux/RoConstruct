// from server: 100% by auto
// roc 2009-06 00735110  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00735110
//
// 00735110  56                   push esi
// 00735111  57                   push edi
// 00735112  8bf1                 mov esi, ecx
// 00735114  33ff                 xor edi, edi
// 00735116  397e0c               cmp dword ptr [esi + 0xc], edi
// 00735119  742e                 je 0x735149
// 0073511b  8b06                 mov eax, dword ptr [esi]
// 0073511d  3bc7                 cmp eax, edi
// 0073511f  7407                 je 0x735128
// 00735121  50                   push eax
// 00735122  ff1564ed8900         call dword ptr [0x89ed64]
// 00735128  8b4604               mov eax, dword ptr [esi + 4]
// 0073512b  3bc7                 cmp eax, edi
// 0073512d  7407                 je 0x735136
// 0073512f  50                   push eax
// 00735130  ff1560e18900         call dword ptr [0x89e160]
// 00735136  8b4614               mov eax, dword ptr [esi + 0x14]
// 00735139  3bc7                 cmp eax, edi
// 0073513b  740c                 je 0x735149
// 0073513d  8b4814               mov ecx, dword ptr [eax + 0x14]
// 00735140  50                   push eax
// 00735141  e8fafeffff           call 0x735040
// 00735146  897e14               mov dword ptr [esi + 0x14], edi
// 00735149  893e                 mov dword ptr [esi], edi
// 0073514b  897e04               mov dword ptr [esi + 4], edi
// 0073514e  897e08               mov dword ptr [esi + 8], edi
// 00735151  897e14               mov dword ptr [esi + 0x14], edi
// 00735154  897e0c               mov dword ptr [esi + 0xc], edi
// 00735157  5f                   pop edi
// 00735158  5e                   pop esi
// 00735159  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Clear@CXTPImageManagerIconHandle@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
