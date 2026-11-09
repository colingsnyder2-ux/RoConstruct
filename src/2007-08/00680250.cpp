// from server: 100% by auto
// roc 2007-08 00680250  unit: CXTPBufferDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00680250
//
// 00680250  8b442414             mov eax, dword ptr [esp + 0x14]
// 00680254  8b542410             mov edx, dword ptr [esp + 0x10]
// 00680258  8b4904               mov ecx, dword ptr [ecx + 4]
// 0068025b  50                   push eax
// 0068025c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00680260  52                   push edx
// 00680261  8b542410             mov edx, dword ptr [esp + 0x10]
// 00680265  50                   push eax
// 00680266  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068026a  52                   push edx
// 0068026b  50                   push eax
// 0068026c  51                   push ecx
// 0068026d  ff15c4ec7700         call dword ptr [0x77ecc4]
// 00680273  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?DrawTextExA@CDC@@UAEHPADHPAUtagRECT@@IPAUtagDRAWTEXTPARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
