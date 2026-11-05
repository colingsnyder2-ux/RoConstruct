// from server: 100% by auto
// roc 2007-03 00662010  unit: seg_00660000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00662010
//
// 00662010  8b442408             mov eax, dword ptr [esp + 8]
// 00662014  8b542404             mov edx, dword ptr [esp + 4]
// 00662018  50                   push eax
// 00662019  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0066201c  52                   push edx
// 0066201d  689a010000           push 0x19a
// 00662022  50                   push eax
// 00662023  ff1550ee7700         call dword ptr [0x77ee50]
// 00662029  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\docmgr.cpp (function ?SetItemData@CListBox@@QAEHHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmgr.cpp
