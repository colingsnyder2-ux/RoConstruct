// from server: 100% by auto
// roc 2007-03 0067fce0  unit: seg_00670000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067fce0
//
// 0067fce0  8b442404             mov eax, dword ptr [esp + 4]
// 0067fce4  50                   push eax
// 0067fce5  e886eeffff           call 0x67eb70
// 0067fcea  33c0                 xor eax, eax
// 0067fcec  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnActivate@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
