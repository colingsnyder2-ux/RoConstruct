// from server: 100% by auto
// roc 2007-03 0040bc80  unit: seg_00400000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040bc80
//
// 0040bc80  8b442404             mov eax, dword ptr [esp + 4]
// 0040bc84  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040bc87  6a00                 push 0
// 0040bc89  50                   push eax
// 0040bc8a  6882010000           push 0x182
// 0040bc8f  51                   push ecx
// 0040bc90  ff1550ee7700         call dword ptr [0x77ee50]
// 0040bc96  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winctrl2.cpp (function ?DeleteString@CListBox@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl2.cpp
