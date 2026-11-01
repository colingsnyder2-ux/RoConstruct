// from server: 100% by auto
// roc 2007-03 00651480  unit: seg_00650000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651480
//
// 00651480  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00651483  6a00                 push 0
// 00651485  6a00                 push 0
// 00651487  680a110000           push 0x110a
// 0065148c  50                   push eax
// 0065148d  ff1550ee7700         call dword ptr [0x77ee50]
// 00651493  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelltreectrl.cpp (function ?GetRootItem@CTreeCtrl@@QBEPAU_TREEITEM@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelltreectrl.cpp
