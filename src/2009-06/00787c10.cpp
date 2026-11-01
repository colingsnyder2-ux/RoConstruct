// from server: 100% by auto
// roc 2009-06 00787c10  unit: CXTPToolTipContext  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787c10
//
// 00787c10  8b442408             mov eax, dword ptr [esp + 8]
// 00787c14  50                   push eax
// 00787c15  e856f3ffff           call 0x786f70
// 00787c1a  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnAddTool@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
