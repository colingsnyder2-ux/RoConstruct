// from server: 100% by auto
// roc 2011-06 008745c0  unit: CXTPToolTipContext  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008745c0
//
// 008745c0  8b442408             mov eax, dword ptr [esp + 8]
// 008745c4  8b542404             mov edx, dword ptr [esp + 4]
// 008745c8  6a01                 push 1
// 008745ca  50                   push eax
// 008745cb  52                   push edx
// 008745cc  e86ff7ffff           call 0x873d40
// 008745d1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dbcore.cpp (function ?GetFieldValue@CRecordset@@QAEXFAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dbcore.cpp
