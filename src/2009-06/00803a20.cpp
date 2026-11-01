// from server: 100% by auto
// roc 2009-06 00803a20  unit: CXTColorLum  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00803a20
//
// 00803a20  8b442404             mov eax, dword ptr [esp + 4]
// 00803a24  56                   push esi
// 00803a25  50                   push eax
// 00803a26  8bf1                 mov esi, ecx
// 00803a28  e82d5ef1ff           call 0x71985a
// 00803a2d  6a00                 push 0
// 00803a2f  c705cc2aa50002000000 mov dword ptr [0xa52acc], 2
// 00803a39  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00803a3c  6a00                 push 0
// 00803a3e  51                   push ecx
// 00803a3f  ff157cee8900         call dword ptr [0x89ee7c]
// 00803a45  5e                   pop esi
// 00803a46  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnSetFocus@CXTPColorLum@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
