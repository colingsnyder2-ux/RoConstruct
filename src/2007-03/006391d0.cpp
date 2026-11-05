// from server: 100% by auto
// roc 2007-03 006391d0  unit: seg_00630000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006391d0
//
// 006391d0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006391d4  8b542410             mov edx, dword ptr [esp + 0x10]
// 006391d8  8b4904               mov ecx, dword ptr [ecx + 4]
// 006391db  50                   push eax
// 006391dc  8b442410             mov eax, dword ptr [esp + 0x10]
// 006391e0  52                   push edx
// 006391e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 006391e5  50                   push eax
// 006391e6  8b442410             mov eax, dword ptr [esp + 0x10]
// 006391ea  52                   push edx
// 006391eb  50                   push eax
// 006391ec  51                   push ecx
// 006391ed  ff1528d17700         call dword ptr [0x77d128]
// 006391f3  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?DrawTextExA@CDC@@UAEHPADHPAUtagRECT@@IPAUtagDRAWTEXTPARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
