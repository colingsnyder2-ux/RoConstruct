// from server: 100% by auto
// roc 2009-06 007581a0  unit: CXTTreeBase  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007581a0
//
// 007581a0  56                   push esi
// 007581a1  8bf1                 mov esi, ecx
// 007581a3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007581a6  e8313d0f00           call 0x84bedc
// 007581ab  a900020000           test eax, 0x200
// 007581b0  741e                 je 0x7581d0
// 007581b2  837e1400             cmp dword ptr [esi + 0x14], 0
// 007581b6  7418                 je 0x7581d0
// 007581b8  8b4634               mov eax, dword ptr [esi + 0x34]
// 007581bb  6a00                 push 0
// 007581bd  c7461400000000       mov dword ptr [esi + 0x14], 0
// 007581c4  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007581c7  6a00                 push 0
// 007581c9  51                   push ecx
// 007581ca  ff157cee8900         call dword ptr [0x89ee7c]
// 007581d0  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007581d3  e8300efcff           call 0x719008
// 007581d8  5e                   pop esi
// 007581d9  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnNcMouseMove@CXTPTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
