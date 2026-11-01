// from server: 100% by auto
// roc 2009-12 00860ea0  unit: CXTPToolTipContextToolTip  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00860ea0
//
// 00860ea0  6a00                 push 0
// 00860ea2  e8e9f8ffff           call 0x860790
// 00860ea7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnMouseMove@CXTPToolTipContextToolTip@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
