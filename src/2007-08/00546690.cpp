// from server: 100% by auto
// roc 2007-08 00546690  unit: RBX::MD5HasherImpl  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00546690
//
// 00546690  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00546694  8d44240c             lea eax, [esp + 0xc]
// 00546698  50                   push eax
// 00546699  51                   push ecx
// 0054669a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0054669e  e89dfcffff           call 0x546340
// 005466a3  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\daoview.cpp (function ?Format@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAAXPBDZZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daoview.cpp
