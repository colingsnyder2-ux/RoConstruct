// from server: 100% by auto
// roc 2009-06 00787c20  unit: CXTPToolTipContext  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787c20
//
// 00787c20  8b442404             mov eax, dword ptr [esp + 4]
// 00787c24  50                   push eax
// 00787c25  e806f4ffff           call 0x787030
// 00787c2a  33c0                 xor eax, eax
// 00787c2c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnActivate@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
