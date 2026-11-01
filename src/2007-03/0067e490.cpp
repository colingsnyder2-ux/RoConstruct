// from server: 100% by auto
// roc 2007-03 0067e490  unit: seg_00670000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067e490
//
// 0067e490  6a00                 push 0
// 0067e492  e809f9ffff           call 0x67dda0
// 0067e497  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnMouseMove@CXTPToolTipContextToolTip@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
