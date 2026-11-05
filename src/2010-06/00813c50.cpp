// from server: 100% by auto
// roc 2010-06 00813c50  unit: CXTPToolTipContextToolTip  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00813c50
//
// 00813c50  8b442408             mov eax, dword ptr [esp + 8]
// 00813c54  89812c010000         mov dword ptr [ecx + 0x12c], eax
// 00813c5a  33c0                 xor eax, eax
// 00813c5c  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetImage@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
