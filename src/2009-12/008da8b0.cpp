// from server: 100% by auto
// roc 2009-12 008da8b0  unit: CXTColorHex  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008da8b0
//
// 008da8b0  c7416000000000       mov dword ptr [ecx + 0x60], 0
// 008da8b7  e87495f1ff           call 0x7f3e30
// 008da8bc  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonUp@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
