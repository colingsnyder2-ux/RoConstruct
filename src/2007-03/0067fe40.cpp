// from server: 100% by auto
// roc 2007-03 0067fe40  unit: seg_00670000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067fe40
//
// 0067fe40  8b442408             mov eax, dword ptr [esp + 8]
// 0067fe44  8b542404             mov edx, dword ptr [esp + 4]
// 0067fe48  6a01                 push 1
// 0067fe4a  50                   push eax
// 0067fe4b  52                   push edx
// 0067fe4c  e8eff7ffff           call 0x67f640
// 0067fe51  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dbcore.cpp (function ?GetFieldValue@CRecordset@@QAEXFAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbcore.cpp
