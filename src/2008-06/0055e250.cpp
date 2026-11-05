// from server: 100% by auto
// roc 2008-06 0055e250  unit: RBX::VInstance::?$NonFactoryProduct  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e250
//
// 0055e250  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0055e254  8d44240c             lea eax, [esp + 0xc]
// 0055e258  50                   push eax
// 0055e259  51                   push ecx
// 0055e25a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055e25e  e87df8ffff           call 0x55dae0
// 0055e263  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?Format@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAAXPBDZZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
