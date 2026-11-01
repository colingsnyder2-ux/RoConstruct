// from server: 100% by auto
// roc 2009-12 00862db0  unit: CXTPToolTipContext  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00862db0
//
// 00862db0  8b442408             mov eax, dword ptr [esp + 8]
// 00862db4  8b542404             mov edx, dword ptr [esp + 4]
// 00862db8  6a01                 push 1
// 00862dba  50                   push eax
// 00862dbb  52                   push edx
// 00862dbc  e86ff7ffff           call 0x862530
// 00862dc1  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dbcore.cpp (function ?GetFieldValue@CRecordset@@QAEXFAAV?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbcore.cpp
