// from server: 100% by auto
// roc 2010-06 00813c60  unit: CXTPToolTipContextToolTip  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00813c60
//
// 00813c60  8b442408             mov eax, dword ptr [esp + 8]
// 00813c64  50                   push eax
// 00813c65  81c128010000         add ecx, 0x128
// 00813c6b  ff158cce9e00         call dword ptr [0x9ece8c]
// 00813c71  33c0                 xor eax, eax
// 00813c73  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?OnSetTitle@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
