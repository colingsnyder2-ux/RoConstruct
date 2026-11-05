// from server: 100% by auto
// roc 2007-08 00643e40  unit: CXTPCommandBar  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00643e40
//
// 00643e40  8b442414             mov eax, dword ptr [esp + 0x14]
// 00643e44  8b542410             mov edx, dword ptr [esp + 0x10]
// 00643e48  8b4904               mov ecx, dword ptr [ecx + 4]
// 00643e4b  50                   push eax
// 00643e4c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00643e50  52                   push edx
// 00643e51  8b542410             mov edx, dword ptr [esp + 0x10]
// 00643e55  50                   push eax
// 00643e56  8b442410             mov eax, dword ptr [esp + 0x10]
// 00643e5a  52                   push edx
// 00643e5b  50                   push eax
// 00643e5c  51                   push ecx
// 00643e5d  ff1520d17700         call dword ptr [0x77d120]
// 00643e63  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?DrawTextExA@CDC@@UAEHPADHPAUtagRECT@@IPAUtagDRAWTEXTPARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
