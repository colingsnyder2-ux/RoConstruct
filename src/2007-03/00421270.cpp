// from server: 100% by auto
// roc 2007-03 00421270  unit: seg_00420000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00421270
//
// 00421270  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00421273  50                   push eax
// 00421274  ff1518ed7700         call dword ptr [0x77ed18]
// 0042127a  50                   push eax
// 0042127b  e8ced31f00           call 0x61e64e
// 00421280  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
