// from server: 100% by auto
// roc 2007-03 00545f90  unit: seg_00540000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00545f90
//
// 00545f90  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00545f94  8d44240c             lea eax, [esp + 0xc]
// 00545f98  50                   push eax
// 00545f99  51                   push ecx
// 00545f9a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00545f9e  e83dfdffff           call 0x545ce0
// 00545fa3  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\daoview.cpp (function ?Format@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAAXPBDZZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daoview.cpp
