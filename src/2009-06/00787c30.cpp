// from server: 100% by auto
// roc 2009-06 00787c30  unit: CXTPToolTipContext  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787c30
//
// 00787c30  8b442408             mov eax, dword ptr [esp + 8]
// 00787c34  50                   push eax
// 00787c35  e856f4ffff           call 0x787090
// 00787c3a  33c0                 xor eax, eax
// 00787c3c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnRelayEvent@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
