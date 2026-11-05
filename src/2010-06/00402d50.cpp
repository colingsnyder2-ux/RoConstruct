// from server: 100% by auto
// roc 2010-06 00402d50  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402d50
//
// 00402d50  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00402d53  50                   push eax
// 00402d54  ff154cba9e00         call dword ptr [0x9eba4c]
// 00402d5a  50                   push eax
// 00402d5b  e80a4f3a00           call 0x7a7c6a
// 00402d60  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
