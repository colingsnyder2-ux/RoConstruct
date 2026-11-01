// from server: 100% by auto
// roc 2009-12 008062e0  unit: CRgn  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008062e0
//
// 008062e0  8b4138               mov eax, dword ptr [ecx + 0x38]
// 008062e3  85c0                 test eax, eax
// 008062e5  750a                 jne 0x8062f1
// 008062e7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008062ea  50                   push eax
// 008062eb  ff15bccb9800         call dword ptr [0x98cbbc]
// 008062f1  50                   push eax
// 008062f2  e833d8feff           call 0x7f3b2a
// 008062f7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetOwner@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
