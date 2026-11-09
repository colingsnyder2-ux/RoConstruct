// from server: 100% by auto
// roc 2009-12 0040c8b0  unit: CNullDoc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040c8b0
//
// 0040c8b0  8b442408             mov eax, dword ptr [esp + 8]
// 0040c8b4  8b542404             mov edx, dword ptr [esp + 4]
// 0040c8b8  50                   push eax
// 0040c8b9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040c8bc  52                   push edx
// 0040c8bd  6881010000           push 0x181
// 0040c8c2  50                   push eax
// 0040c8c3  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0040c8c9  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\winctrl2.cpp (function ?InsertString@CListBox@@QAEHHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl2.cpp
