// from server: 100% by auto
// roc 2008-06 0070cc90  unit: CXTPToolTipContext  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070cc90
//
// 0070cc90  8b442408             mov eax, dword ptr [esp + 8]
// 0070cc94  8b542404             mov edx, dword ptr [esp + 4]
// 0070cc98  6a01                 push 1
// 0070cc9a  50                   push eax
// 0070cc9b  52                   push edx
// 0070cc9c  e86ff7ffff           call 0x70c410
// 0070cca1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dbcore.cpp (function ?GetFieldValue@CRecordset@@QAEXFAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbcore.cpp
