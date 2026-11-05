// from server: 100% by auto
// roc 2009-06 00765a20  unit: CListBox  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00765a20
//
// 00765a20  8b442408             mov eax, dword ptr [esp + 8]
// 00765a24  8b542404             mov edx, dword ptr [esp + 4]
// 00765a28  50                   push eax
// 00765a29  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00765a2c  52                   push edx
// 00765a2d  689a010000           push 0x19a
// 00765a32  50                   push eax
// 00765a33  ff1590ee8900         call dword ptr [0x89ee90]
// 00765a39  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetItemData@CListBox@@QAEHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
