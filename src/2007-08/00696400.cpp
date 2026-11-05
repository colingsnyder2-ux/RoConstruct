// from server: 100% by auto
// roc 2007-08 00696400  unit: CXTPToolTipContext  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00696400
//
// 00696400  8b442408             mov eax, dword ptr [esp + 8]
// 00696404  8b542404             mov edx, dword ptr [esp + 4]
// 00696408  6a01                 push 1
// 0069640a  50                   push eax
// 0069640b  52                   push edx
// 0069640c  e8eff7ffff           call 0x695c00
// 00696411  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dbcore.cpp (function ?GetFieldValue@CRecordset@@QAEXFAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbcore.cpp
