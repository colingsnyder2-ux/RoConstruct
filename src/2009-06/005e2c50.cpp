// from server: 100% by auto
// roc 2009-06 005e2c50  unit: boost::Vthread::?$sp_counted_impl_p  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e2c50
//
// 005e2c50  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005e2c54  8d44240c             lea eax, [esp + 0xc]
// 005e2c58  50                   push eax
// 005e2c59  51                   push ecx
// 005e2c5a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005e2c5e  e84dfbffff           call 0x5e27b0
// 005e2c63  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?Format@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAAXPBDZZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
