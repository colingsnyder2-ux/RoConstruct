// from server: 100% by auto
// roc 2009-06 00802c60  unit: CXTColorBase  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00802c60
//
// 00802c60  56                   push esi
// 00802c61  8bf1                 mov esi, ecx
// 00802c63  ff1544ee8900         call dword ptr [0x89ee44]
// 00802c69  8bce                 mov ecx, esi
// 00802c6b  e89863f1ff           call 0x719008
// 00802c70  5e                   pop esi
// 00802c71  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnLButtonUp@CXTPColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
