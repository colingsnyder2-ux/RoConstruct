// from server: 100% by auto
// roc 2009-12 00850060  unit: CXTPPropExchange  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850060
//
// 00850060  b801000000           mov eax, 1
// 00850065  894138               mov dword ptr [ecx + 0x38], eax
// 00850068  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?OnBeforeExchange@CXTPPropExchange@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
