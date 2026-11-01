// from server: 100% by auto
// roc 2009-06 00761290  unit: ATL::CRegObject  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761290
//
// 00761290  e8bbffffff           call 0x761250
// 00761295  0fb6c0               movzx eax, al
// 00761298  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsClearTypeTextQualitySupported@CXTPSystemVersion@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
