// from server: 100% by auto
// roc 2009-12 0040c890  unit: CNullDoc  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040c890
//
// 0040c890  8b442404             mov eax, dword ptr [esp + 4]
// 0040c894  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040c897  6a00                 push 0
// 0040c899  50                   push eax
// 0040c89a  6882010000           push 0x182
// 0040c89f  51                   push ecx
// 0040c8a0  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0040c8a6  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winctrl2.cpp (function ?DeleteString@CListBox@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl2.cpp
