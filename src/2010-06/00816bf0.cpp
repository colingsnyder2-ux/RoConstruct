// from server: 100% by auto
// roc 2010-06 00816bf0  unit: CXTPToolTipContext  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816bf0
//
// 00816bf0  8b442408             mov eax, dword ptr [esp + 8]
// 00816bf4  50                   push eax
// 00816bf5  e866f3ffff           call 0x815f60
// 00816bfa  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnAddTool@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
