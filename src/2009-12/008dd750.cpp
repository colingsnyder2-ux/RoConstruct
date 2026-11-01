// from server: 100% by auto
// roc 2009-12 008dd750  unit: CXTColorBase  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dd750
//
// 008dd750  56                   push esi
// 008dd751  8bf1                 mov esi, ecx
// 008dd753  ff1520cc9800         call dword ptr [0x98cc20]
// 008dd759  8bce                 mov ecx, esi
// 008dd75b  e8d066f1ff           call 0x7f3e30
// 008dd760  5e                   pop esi
// 008dd761  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnLButtonUp@CXTPColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
