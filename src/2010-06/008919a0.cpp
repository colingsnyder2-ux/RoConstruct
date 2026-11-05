// from server: 100% by auto
// roc 2010-06 008919a0  unit: CXTColorBase  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008919a0
//
// 008919a0  56                   push esi
// 008919a1  8bf1                 mov esi, ecx
// 008919a3  ff158cbc9e00         call dword ptr [0x9ebc8c]
// 008919a9  8bce                 mov ecx, esi
// 008919ab  e8c065f1ff           call 0x7a7f70
// 008919b0  5e                   pop esi
// 008919b1  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?OnLButtonUp@CXTColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
