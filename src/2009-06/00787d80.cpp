// from server: 100% by auto
// roc 2009-06 00787d80  unit: CXTPToolTipContext  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787d80
//
// 00787d80  8b442408             mov eax, dword ptr [esp + 8]
// 00787d84  8b542404             mov edx, dword ptr [esp + 4]
// 00787d88  6a01                 push 1
// 00787d8a  50                   push eax
// 00787d8b  52                   push edx
// 00787d8c  e86ff7ffff           call 0x787500
// 00787d91  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dbcore.cpp (function ?GetFieldValue@CRecordset@@QAEXFAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbcore.cpp
