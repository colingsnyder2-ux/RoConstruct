// from server: 100% by auto
// roc 2007-03 00686650  unit: seg_00680000  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686650
//
// 00686650  e8dbffffff           call 0x686630
// 00686655  0fb6c0               movzx eax, al
// 00686658  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsClearTypeTextQualitySupported@CXTPSystemVersion@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
