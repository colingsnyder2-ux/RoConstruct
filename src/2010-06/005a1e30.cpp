// from server: 100% by auto
// roc 2010-06 005a1e30  unit: std::runtime_error  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005a1e30
//
// 005a1e30  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005a1e34  8d44240c             lea eax, [esp + 0xc]
// 005a1e38  50                   push eax
// 005a1e39  51                   push ecx
// 005a1e3a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005a1e3e  e80dfaffff           call 0x5a1850
// 005a1e43  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?Format@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAAXPBDZZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
