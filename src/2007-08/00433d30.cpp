// from server: 100% by auto
// roc 2007-08 00433d30  unit: CBrowserFrameWnd  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00433d30
//
// 00433d30  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00433d33  50                   push eax
// 00433d34  ff15b4ed7700         call dword ptr [0x77edb4]
// 00433d3a  50                   push eax
// 00433d3b  e8b8c51f00           call 0x6302f8
// 00433d40  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
