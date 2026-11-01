// from server: 100% by auto
// roc 2007-03 00620e10  unit: seg_00620000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00620e10
//
// 00620e10  8b442408             mov eax, dword ptr [esp + 8]
// 00620e14  8b542404             mov edx, dword ptr [esp + 4]
// 00620e18  50                   push eax
// 00620e19  52                   push edx
// 00620e1a  e8c191e9ff           call 0x4b9fe0
// 00620e1f  8bc8                 mov ecx, eax
// 00620e21  e8a0dbffff           call 0x61e9c6
// 00620e26  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarCustomProperties.cpp (function ?SetAt@?$CMap@V?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PBDVCOleVariant@@AAV3@@@QAEXPBDAAVCOleVariant@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCustomProperties.cpp
