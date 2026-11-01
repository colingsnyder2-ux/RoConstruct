// from server: 100% by auto
// roc 2009-06 00784c40  unit: CXTPToolTipContextToolTip  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00784c40
//
// 00784c40  8b442408             mov eax, dword ptr [esp + 8]
// 00784c44  89812c010000         mov dword ptr [ecx + 0x12c], eax
// 00784c4a  33c0                 xor eax, eax
// 00784c4c  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetImage@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
