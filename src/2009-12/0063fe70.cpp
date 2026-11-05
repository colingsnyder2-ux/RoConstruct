// from server: 100% by auto
// roc 2009-12 0063fe70  unit: std::runtime_error  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063fe70
//
// 0063fe70  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0063fe74  8d44240c             lea eax, [esp + 0xc]
// 0063fe78  50                   push eax
// 0063fe79  51                   push ecx
// 0063fe7a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0063fe7e  e80dfaffff           call 0x63f890
// 0063fe83  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\daoview.cpp (function ?Format@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAAXPBDZZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daoview.cpp
