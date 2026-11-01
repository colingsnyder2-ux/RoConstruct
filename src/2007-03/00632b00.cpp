// from server: 100% by auto
// roc 2007-03 00632b00  unit: seg_00630000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00632b00
//
// 00632b00  8b442414             mov eax, dword ptr [esp + 0x14]
// 00632b04  85c0                 test eax, eax
// 00632b06  7403                 je 0x632b0b
// 00632b08  8b4004               mov eax, dword ptr [eax + 4]
// 00632b0b  8b542420             mov edx, dword ptr [esp + 0x20]
// 00632b0f  52                   push edx
// 00632b10  8b542420             mov edx, dword ptr [esp + 0x20]
// 00632b14  52                   push edx
// 00632b15  8b542420             mov edx, dword ptr [esp + 0x20]
// 00632b19  52                   push edx
// 00632b1a  8b542418             mov edx, dword ptr [esp + 0x18]
// 00632b1e  50                   push eax
// 00632b1f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00632b23  50                   push eax
// 00632b24  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00632b28  52                   push edx
// 00632b29  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00632b2d  50                   push eax
// 00632b2e  8b4104               mov eax, dword ptr [ecx + 4]
// 00632b31  52                   push edx
// 00632b32  50                   push eax
// 00632b33  ff15e4d07700         call dword ptr [0x77d0e4]
// 00632b39  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\winbtn.cpp (function ?BitBlt@CDC@@QAEHHHHHPAV1@HHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winbtn.cpp
