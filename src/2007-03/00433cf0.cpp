// from server: 100% by auto
// roc 2007-03 00433cf0  unit: seg_00430000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00433cf0
//
// 00433cf0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00433cf3  50                   push eax
// 00433cf4  ff1578ed7700         call dword ptr [0x77ed78]
// 00433cfa  50                   push eax
// 00433cfb  e88caa1e00           call 0x61e78c
// 00433d00  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
