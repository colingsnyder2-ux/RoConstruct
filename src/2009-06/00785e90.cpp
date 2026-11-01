// from server: 100% by auto
// roc 2009-06 00785e90  unit: CXTPToolTipContextToolTip  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00785e90
//
// 00785e90  6a00                 push 0
// 00785e92  e8e9f8ffff           call 0x785780
// 00785e97  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnMouseMove@CXTPToolTipContextToolTip@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
