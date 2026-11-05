// from server: 100% by auto
// roc 2007-08 006761e0  unit: CListBox  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006761e0
//
// 006761e0  8b442408             mov eax, dword ptr [esp + 8]
// 006761e4  8b542404             mov edx, dword ptr [esp + 4]
// 006761e8  50                   push eax
// 006761e9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006761ec  52                   push edx
// 006761ed  689a010000           push 0x19a
// 006761f2  50                   push eax
// 006761f3  ff15d8ec7700         call dword ptr [0x77ecd8]
// 006761f9  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\docmgr.cpp (function ?SetItemData@CListBox@@QAEHHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmgr.cpp
