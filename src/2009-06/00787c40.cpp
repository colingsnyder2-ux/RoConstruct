// from server: 100% by auto
// roc 2009-06 00787c40  unit: CXTPToolTipContext  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787c40
//
// 00787c40  8b442408             mov eax, dword ptr [esp + 8]
// 00787c44  50                   push eax
// 00787c45  e8a6f6ffff           call 0x7872f0
// 00787c4a  33c0                 xor eax, eax
// 00787c4c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnRelayEvent@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
