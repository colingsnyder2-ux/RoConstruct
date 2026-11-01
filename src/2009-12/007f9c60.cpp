// from server: 100% by auto
// roc 2009-12 007f9c60  unit: CXTPControlComboBoxList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9c60
//
// 007f9c60  8b442408             mov eax, dword ptr [esp + 8]
// 007f9c64  8b542404             mov edx, dword ptr [esp + 4]
// 007f9c68  50                   push eax
// 007f9c69  52                   push edx
// 007f9c6a  e8018fc2ff           call 0x422b70
// 007f9c6f  8bc8                 mov ecx, eax
// 007f9c71  e8f6c71200           call 0x92646c
// 007f9c76  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarCustomProperties.cpp (function ?SetAt@?$CMap@V?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PBDVCOleVariant@@AAV3@@@QAEXPBDAAVCOleVariant@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCustomProperties.cpp
