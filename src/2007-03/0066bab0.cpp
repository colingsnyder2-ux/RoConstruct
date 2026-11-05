// from server: 100% by auto
// roc 2007-03 0066bab0  unit: seg_00660000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066bab0
//
// 0066bab0  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066bab4  8b542410             mov edx, dword ptr [esp + 0x10]
// 0066bab8  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066babb  50                   push eax
// 0066babc  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066bac0  52                   push edx
// 0066bac1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0066bac5  50                   push eax
// 0066bac6  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066baca  52                   push edx
// 0066bacb  50                   push eax
// 0066bacc  51                   push ecx
// 0066bacd  ff158cef7700         call dword ptr [0x77ef8c]
// 0066bad3  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?DrawTextExA@CDC@@UAEHPADHPAUtagRECT@@IPAUtagDRAWTEXTPARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
