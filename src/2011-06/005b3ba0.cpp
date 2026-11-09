// from server: 100% by auto
// roc 2011-06 005b3ba0  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005b3ba0
//
// 005b3ba0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b3ba4  8d44240c             lea eax, [esp + 0xc]
// 005b3ba8  50                   push eax
// 005b3ba9  51                   push ecx
// 005b3baa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b3bae  e89df3ffff           call 0x5b2f50
// 005b3bb3  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?Format@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAAXPBDZZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
