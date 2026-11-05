// from server: 100% by auto
// roc 2007-03 0040bca0  unit: seg_00400000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040bca0
//
// 0040bca0  8b442408             mov eax, dword ptr [esp + 8]
// 0040bca4  8b542404             mov edx, dword ptr [esp + 4]
// 0040bca8  50                   push eax
// 0040bca9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040bcac  52                   push edx
// 0040bcad  6881010000           push 0x181
// 0040bcb2  50                   push eax
// 0040bcb3  ff1550ee7700         call dword ptr [0x77ee50]
// 0040bcb9  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\winctrl2.cpp (function ?InsertString@CListBox@@QAEHHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl2.cpp
