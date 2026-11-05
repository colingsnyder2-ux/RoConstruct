// from server: 100% by auto
// roc 2009-06 00403030  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403030
//
// 00403030  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00403033  50                   push eax
// 00403034  ff1598ee8900         call dword ptr [0x89ee98]
// 0040303a  50                   push eax
// 0040303b  e8c25c3100           call 0x718d02
// 00403040  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
