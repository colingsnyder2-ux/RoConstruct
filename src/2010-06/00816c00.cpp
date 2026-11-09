// from server: 100% by auto
// roc 2010-06 00816c00  unit: CXTPToolTipContext  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816c00
//
// 00816c00  8b442404             mov eax, dword ptr [esp + 4]
// 00816c04  50                   push eax
// 00816c05  e816f4ffff           call 0x816020
// 00816c0a  33c0                 xor eax, eax
// 00816c0c  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnActivate@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
