// from server: 100% by auto
// roc 2009-12 00817e70  unit: CXTPCommandBarsOptions  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00817e70
//
// 00817e70  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00817e73  50                   push eax
// 00817e74  ff15e0cb9800         call dword ptr [0x98cbe0]
// 00817e7a  50                   push eax
// 00817e7b  e8b0e51000           call 0x926430
// 00817e80  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
