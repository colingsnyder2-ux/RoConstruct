// from server: 100% by auto
// roc 2010-06 00816d60  unit: CXTPToolTipContext  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816d60
//
// 00816d60  8b442408             mov eax, dword ptr [esp + 8]
// 00816d64  8b542404             mov edx, dword ptr [esp + 4]
// 00816d68  6a01                 push 1
// 00816d6a  50                   push eax
// 00816d6b  52                   push edx
// 00816d6c  e86ff7ffff           call 0x8164e0
// 00816d71  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dbcore.cpp (function ?GetFieldValue@CRecordset@@QAEXFAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbcore.cpp
