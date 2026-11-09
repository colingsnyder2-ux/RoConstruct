// from server: 100% by auto
// roc 2009-12 007fe160  unit: CXTPPaintManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe160
//
// 007fe160  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fe164  85c0                 test eax, eax
// 007fe166  7403                 je 0x7fe16b
// 007fe168  8b4004               mov eax, dword ptr [eax + 4]
// 007fe16b  8b542420             mov edx, dword ptr [esp + 0x20]
// 007fe16f  52                   push edx
// 007fe170  8b542420             mov edx, dword ptr [esp + 0x20]
// 007fe174  52                   push edx
// 007fe175  8b542420             mov edx, dword ptr [esp + 0x20]
// 007fe179  52                   push edx
// 007fe17a  8b542418             mov edx, dword ptr [esp + 0x18]
// 007fe17e  50                   push eax
// 007fe17f  8b442420             mov eax, dword ptr [esp + 0x20]
// 007fe183  50                   push eax
// 007fe184  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fe188  52                   push edx
// 007fe189  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007fe18d  50                   push eax
// 007fe18e  8b4104               mov eax, dword ptr [ecx + 4]
// 007fe191  52                   push edx
// 007fe192  50                   push eax
// 007fe193  ff1548b19800         call dword ptr [0x98b148]
// 007fe199  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?BitBlt@CDC@@QAEHHHHHPAV1@HHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
