// from server: 100% by auto
// roc 2007-03 00652b70  unit: seg_00650000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652b70
//
// 00652b70  56                   push esi
// 00652b71  8bf1                 mov esi, ecx
// 00652b73  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00652b76  e849800e00           call 0x73abc4
// 00652b7b  a900020000           test eax, 0x200
// 00652b80  741e                 je 0x652ba0
// 00652b82  837e1400             cmp dword ptr [esi + 0x14], 0
// 00652b86  7418                 je 0x652ba0
// 00652b88  8b4634               mov eax, dword ptr [esi + 0x34]
// 00652b8b  6a00                 push 0
// 00652b8d  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00652b94  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00652b97  6a00                 push 0
// 00652b99  51                   push ecx
// 00652b9a  ff1554ee7700         call dword ptr [0x77ee54]
// 00652ba0  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00652ba3  e82abbfcff           call 0x61e6d2
// 00652ba8  5e                   pop esi
// 00652ba9  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnNcMouseMove@CXTPTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
