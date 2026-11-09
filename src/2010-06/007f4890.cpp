// from server: 100% by auto
// roc 2010-06 007f4890  unit: CListBox  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f4890
//
// 007f4890  8b442408             mov eax, dword ptr [esp + 8]
// 007f4894  8b542404             mov edx, dword ptr [esp + 4]
// 007f4898  50                   push eax
// 007f4899  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007f489c  52                   push edx
// 007f489d  689a010000           push 0x19a
// 007f48a2  50                   push eax
// 007f48a3  ff1554ba9e00         call dword ptr [0x9eba54]
// 007f48a9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetItemData@CListBox@@QAEHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
