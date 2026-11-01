// from server: 100% by auto
// roc 2007-03 00620cf0  unit: seg_00620000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00620cf0
//
// 00620cf0  8b442404             mov eax, dword ptr [esp + 4]
// 00620cf4  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00620cf7  6a00                 push 0
// 00620cf9  50                   push eax
// 00620cfa  6886010000           push 0x186
// 00620cff  51                   push ecx
// 00620d00  ff1550ee7700         call dword ptr [0x77ee50]
// 00620d06  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\docmgr.cpp (function ?SetCurSel@CListBox@@QAEHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmgr.cpp
