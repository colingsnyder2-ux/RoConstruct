// from server: 100% by auto
// roc 2008-06 006ed020  unit: CXTPCustomizeCommandsPage  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ed020
//
// 006ed020  8b442408             mov eax, dword ptr [esp + 8]
// 006ed024  8b542404             mov edx, dword ptr [esp + 4]
// 006ed028  50                   push eax
// 006ed029  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006ed02c  52                   push edx
// 006ed02d  689a010000           push 0x19a
// 006ed032  50                   push eax
// 006ed033  ff15142e8000         call dword ptr [0x802e14]
// 006ed039  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetItemData@CListBox@@QAEHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
