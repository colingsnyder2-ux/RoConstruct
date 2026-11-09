// from server: 100% by auto
// roc 2007-08 0040eb70  unit: CChatPrompt  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040eb70
//
// 0040eb70  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040eb73  50                   push eax
// 0040eb74  ff15f8eb7700         call dword ptr [0x77ebf8]
// 0040eb7a  50                   push eax
// 0040eb7b  e840162200           call 0x6301c0
// 0040eb80  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
