// from server: 100% by auto
// roc 2009-12 00862c50  unit: CXTPToolTipContext  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00862c50
//
// 00862c50  8b442404             mov eax, dword ptr [esp + 4]
// 00862c54  50                   push eax
// 00862c55  e8f6f3ffff           call 0x862050
// 00862c5a  33c0                 xor eax, eax
// 00862c5c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnActivate@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
