// from server: 100% by auto
// roc 2009-12 0083c060  unit: CXTPAccessible  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c060
//
// 0083c060  e8bbffffff           call 0x83c020
// 0083c065  0fb6c0               movzx eax, al
// 0083c068  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsClearTypeTextQualitySupported@CXTPSystemVersion@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
