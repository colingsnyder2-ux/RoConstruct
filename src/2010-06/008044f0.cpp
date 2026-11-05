// from server: 100% by auto
// roc 2010-06 008044f0  unit: CXTPPropExchange  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008044f0
//
// 008044f0  8b4128               mov eax, dword ptr [ecx + 0x28]
// 008044f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008044f7  50                   push eax
// 008044f8  51                   push ecx
// 008044f9  e822ffffff           call 0x804420
// 008044fe  83c408               add esp, 8
// 00804501  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@IAEXAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
