// from server: 100% by auto
// roc 2011-06 008e7710  unit: CXTColorHex  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e7710
//
// 008e7710  c7416000000000       mov dword ptr [ecx + 0x60], 0
// 008e7717  e8122ff2ff           call 0x80a62e
// 008e771c  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonUp@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
