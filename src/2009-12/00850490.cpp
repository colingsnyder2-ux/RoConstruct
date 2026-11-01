// from server: 100% by auto
// roc 2009-12 00850490  unit: CXTPPropExchange  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850490
//
// 00850490  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00850493  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00850497  50                   push eax
// 00850498  51                   push ecx
// 00850499  e822ffffff           call 0x8503c0
// 0085049e  83c408               add esp, 8
// 008504a1  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@IAEXAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
