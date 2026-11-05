// from server: 100% by auto
// roc 2009-06 007ffd40  unit: CXTColorHex  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ffd40
//
// 007ffd40  c7416000000000       mov dword ptr [ecx + 0x60], 0
// 007ffd47  e8bc92f1ff           call 0x719008
// 007ffd4c  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonUp@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
