// from server: 100% by auto
// roc 2010-06 0088ea60  unit: CXTColorHex  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088ea60
//
// 0088ea60  c7416000000000       mov dword ptr [ecx + 0x60], 0
// 0088ea67  e80495f1ff           call 0x7a7f70
// 0088ea6c  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonUp@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
