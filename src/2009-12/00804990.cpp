// from server: 100% by auto
// roc 2009-12 00804990  unit: CXTPCommandBar  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00804990
//
// 00804990  8b442414             mov eax, dword ptr [esp + 0x14]
// 00804994  8b542410             mov edx, dword ptr [esp + 0x10]
// 00804998  8b4904               mov ecx, dword ptr [ecx + 4]
// 0080499b  50                   push eax
// 0080499c  8b442410             mov eax, dword ptr [esp + 0x10]
// 008049a0  52                   push edx
// 008049a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008049a5  50                   push eax
// 008049a6  8b442410             mov eax, dword ptr [esp + 0x10]
// 008049aa  52                   push edx
// 008049ab  50                   push eax
// 008049ac  51                   push ecx
// 008049ad  ff1508b19800         call dword ptr [0x98b108]
// 008049b3  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?DrawTextExA@CDC@@UAEHPADHPAUtagRECT@@IPAUtagDRAWTEXTPARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
