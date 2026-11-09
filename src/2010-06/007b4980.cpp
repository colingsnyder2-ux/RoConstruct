// from server: 100% by auto
// roc 2010-06 007b4980  unit: CXTPControlComboBoxList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4980
//
// 007b4980  8b442408             mov eax, dword ptr [esp + 8]
// 007b4984  8b542404             mov edx, dword ptr [esp + 4]
// 007b4988  50                   push eax
// 007b4989  52                   push edx
// 007b498a  e8516cf5ff           call 0x70b5e0
// 007b498f  8bc8                 mov ecx, eax
// 007b4991  e842841c00           call 0x97cdd8
// 007b4996  c20800               ret 8
// library xtp-13.2.1/Source\Calendar\XTPCalendarCustomProperties.cpp (function ?SetAt@?$CMap@V?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PBDVCOleVariant@@AAV3@@@QAEXPBDAAVCOleVariant@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCustomProperties.cpp
