// from server: 100% by auto
// roc 2010-06 007f01c0  unit: CPatchedControlComboBox  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f01c0
//
// 007f01c0  e8bbffffff           call 0x7f0180
// 007f01c5  0fb6c0               movzx eax, al
// 007f01c8  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsClearTypeTextQualitySupported@CXTPSystemVersion@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
