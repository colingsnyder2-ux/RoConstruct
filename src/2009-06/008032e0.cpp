// from server: 100% by auto
// roc 2009-06 008032e0  unit: CXTColorWnd  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008032e0
//
// 008032e0  56                   push esi
// 008032e1  8bf1                 mov esi, ecx
// 008032e3  e8205df1ff           call 0x719008
// 008032e8  6a00                 push 0
// 008032ea  c705cc2aa50000000000 mov dword ptr [0xa52acc], 0
// 008032f4  8b4620               mov eax, dword ptr [esi + 0x20]
// 008032f7  6a00                 push 0
// 008032f9  50                   push eax
// 008032fa  ff157cee8900         call dword ptr [0x89ee7c]
// 00803300  5e                   pop esi
// 00803301  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnKillFocus@CXTPColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
