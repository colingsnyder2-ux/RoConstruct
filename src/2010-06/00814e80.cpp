// from server: 100% by auto
// roc 2010-06 00814e80  unit: CXTPToolTipContextToolTip  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00814e80
//
// 00814e80  6a00                 push 0
// 00814e82  e8e9f8ffff           call 0x814770
// 00814e87  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnMouseMove@CXTPToolTipContextToolTip@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
