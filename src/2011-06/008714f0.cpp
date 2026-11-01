// from server: 100% by auto
// roc 2011-06 008714f0  unit: CXTPToolTipContextToolTip  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008714f0
//
// 008714f0  8b442408             mov eax, dword ptr [esp + 8]
// 008714f4  89812c010000         mov dword ptr [ecx + 0x12c], eax
// 008714fa  33c0                 xor eax, eax
// 008714fc  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetImage@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
