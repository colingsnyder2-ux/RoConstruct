// from server: 100% by auto
// roc 2009-06 0071bad0  unit: CXTPControlComboBoxList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071bad0
//
// 0071bad0  8b442408             mov eax, dword ptr [esp + 8]
// 0071bad4  8b542404             mov edx, dword ptr [esp + 4]
// 0071bad8  50                   push eax
// 0071bad9  52                   push edx
// 0071bada  e861fbffff           call 0x71b640
// 0071badf  8bc8                 mov ecx, eax
// 0071bae1  e8f0031300           call 0x84bed6
// 0071bae6  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarCustomProperties.cpp (function ?SetAt@?$CMap@V?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PBDVCOleVariant@@AAV3@@@QAEXPBDAAVCOleVariant@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCustomProperties.cpp
