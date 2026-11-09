// from server: 100% by auto
// roc 2010-06 00816c10  unit: CXTPToolTipContext  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816c10
//
// 00816c10  8b442408             mov eax, dword ptr [esp + 8]
// 00816c14  50                   push eax
// 00816c15  e866f4ffff           call 0x816080
// 00816c1a  33c0                 xor eax, eax
// 00816c1c  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnRelayEvent@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
