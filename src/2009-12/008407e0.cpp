// from server: 100% by auto
// roc 2009-12 008407e0  unit: CXTPCustomizeCommandsPage  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008407e0
//
// 008407e0  8b442408             mov eax, dword ptr [esp + 8]
// 008407e4  8b542404             mov edx, dword ptr [esp + 4]
// 008407e8  50                   push eax
// 008407e9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008407ec  52                   push edx
// 008407ed  689a010000           push 0x19a
// 008407f2  50                   push eax
// 008407f3  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008407f9  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\docmgr.cpp (function ?SetItemData@CListBox@@QAEHHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmgr.cpp
