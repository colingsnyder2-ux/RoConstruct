// from server: 100% by auto
// roc 2011-06 00403740  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403740
//
// 00403740  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00403743  50                   push eax
// 00403744  ff15b819a400         call dword ptr [0xa419b8]
// 0040374a  50                   push eax
// 0040374b  e8d86b4000           call 0x80a328
// 00403750  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
