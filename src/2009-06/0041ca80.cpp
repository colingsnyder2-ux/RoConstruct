// from server: 100% by auto
// roc 2009-06 0041ca80  unit: CSettingsExplorer  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041ca80
//
// 0041ca80  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0041ca83  50                   push eax
// 0041ca84  ff1538ee8900         call dword ptr [0x89ee38]
// 0041ca8a  50                   push eax
// 0041ca8b  e872c22f00           call 0x718d02
// 0041ca90  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
