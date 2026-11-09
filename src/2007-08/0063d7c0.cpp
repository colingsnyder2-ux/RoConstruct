// from server: 100% by auto
// roc 2007-08 0063d7c0  unit: CXTPPaintManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063d7c0
//
// 0063d7c0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063d7c4  85c0                 test eax, eax
// 0063d7c6  7403                 je 0x63d7cb
// 0063d7c8  8b4004               mov eax, dword ptr [eax + 4]
// 0063d7cb  8b542420             mov edx, dword ptr [esp + 0x20]
// 0063d7cf  52                   push edx
// 0063d7d0  8b542420             mov edx, dword ptr [esp + 0x20]
// 0063d7d4  52                   push edx
// 0063d7d5  8b542420             mov edx, dword ptr [esp + 0x20]
// 0063d7d9  52                   push edx
// 0063d7da  8b542418             mov edx, dword ptr [esp + 0x18]
// 0063d7de  50                   push eax
// 0063d7df  8b442420             mov eax, dword ptr [esp + 0x20]
// 0063d7e3  50                   push eax
// 0063d7e4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063d7e8  52                   push edx
// 0063d7e9  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0063d7ed  50                   push eax
// 0063d7ee  8b4104               mov eax, dword ptr [ecx + 4]
// 0063d7f1  52                   push edx
// 0063d7f2  50                   push eax
// 0063d7f3  ff153cd17700         call dword ptr [0x77d13c]
// 0063d7f9  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?BitBlt@CDC@@QAEHHHHHPAV1@HHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
