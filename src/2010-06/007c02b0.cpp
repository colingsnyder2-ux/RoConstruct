// from server: 100% by auto
// roc 2010-06 007c02b0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c02b0
//
// 007c02b0  56                   push esi
// 007c02b1  57                   push edi
// 007c02b2  8bf1                 mov esi, ecx
// 007c02b4  33ff                 xor edi, edi
// 007c02b6  397e0c               cmp dword ptr [esi + 0xc], edi
// 007c02b9  742e                 je 0x7c02e9
// 007c02bb  8b06                 mov eax, dword ptr [esi]
// 007c02bd  3bc7                 cmp eax, edi
// 007c02bf  7407                 je 0x7c02c8
// 007c02c1  50                   push eax
// 007c02c2  ff1584bb9e00         call dword ptr [0x9ebb84]
// 007c02c8  8b4604               mov eax, dword ptr [esi + 4]
// 007c02cb  3bc7                 cmp eax, edi
// 007c02cd  7407                 je 0x7c02d6
// 007c02cf  50                   push eax
// 007c02d0  ff15d4a09e00         call dword ptr [0x9ea0d4]
// 007c02d6  8b4614               mov eax, dword ptr [esi + 0x14]
// 007c02d9  3bc7                 cmp eax, edi
// 007c02db  740c                 je 0x7c02e9
// 007c02dd  8b4814               mov ecx, dword ptr [eax + 0x14]
// 007c02e0  50                   push eax
// 007c02e1  e8fafeffff           call 0x7c01e0
// 007c02e6  897e14               mov dword ptr [esi + 0x14], edi
// 007c02e9  893e                 mov dword ptr [esi], edi
// 007c02eb  897e04               mov dword ptr [esi + 4], edi
// 007c02ee  897e08               mov dword ptr [esi + 8], edi
// 007c02f1  897e14               mov dword ptr [esi + 0x14], edi
// 007c02f4  897e0c               mov dword ptr [esi + 0xc], edi
// 007c02f7  5f                   pop edi
// 007c02f8  5e                   pop esi
// 007c02f9  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?Clear@CXTPImageManagerIconHandle@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
