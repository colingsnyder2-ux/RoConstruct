// from server: 100% by auto
// roc 2009-12 0080c1c0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080c1c0
//
// 0080c1c0  56                   push esi
// 0080c1c1  57                   push edi
// 0080c1c2  8bf1                 mov esi, ecx
// 0080c1c4  33ff                 xor edi, edi
// 0080c1c6  397e0c               cmp dword ptr [esi + 0xc], edi
// 0080c1c9  742e                 je 0x80c1f9
// 0080c1cb  8b06                 mov eax, dword ptr [esi]
// 0080c1cd  3bc7                 cmp eax, edi
// 0080c1cf  7407                 je 0x80c1d8
// 0080c1d1  50                   push eax
// 0080c1d2  ff15f8c99800         call dword ptr [0x98c9f8]
// 0080c1d8  8b4604               mov eax, dword ptr [esi + 4]
// 0080c1db  3bc7                 cmp eax, edi
// 0080c1dd  7407                 je 0x80c1e6
// 0080c1df  50                   push eax
// 0080c1e0  ff153cb19800         call dword ptr [0x98b13c]
// 0080c1e6  8b4614               mov eax, dword ptr [esi + 0x14]
// 0080c1e9  3bc7                 cmp eax, edi
// 0080c1eb  740c                 je 0x80c1f9
// 0080c1ed  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0080c1f0  50                   push eax
// 0080c1f1  e8fafeffff           call 0x80c0f0
// 0080c1f6  897e14               mov dword ptr [esi + 0x14], edi
// 0080c1f9  893e                 mov dword ptr [esi], edi
// 0080c1fb  897e04               mov dword ptr [esi + 4], edi
// 0080c1fe  897e08               mov dword ptr [esi + 8], edi
// 0080c201  897e14               mov dword ptr [esi + 0x14], edi
// 0080c204  897e0c               mov dword ptr [esi + 0xc], edi
// 0080c207  5f                   pop edi
// 0080c208  5e                   pop esi
// 0080c209  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Clear@CXTPImageManagerIconHandle@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
