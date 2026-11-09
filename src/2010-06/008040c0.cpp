// from server: 100% by auto
// roc 2010-06 008040c0  unit: CXTPPropExchange  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008040c0
//
// 008040c0  b801000000           mov eax, 1
// 008040c5  894138               mov dword ptr [ecx + 0x38], eax
// 008040c8  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?OnBeforeExchange@CXTPPropExchange@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
