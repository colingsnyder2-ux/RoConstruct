// from server: 100% by auto
// roc 2007-08 00649110  unit: CXTPCommandBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00649110
//
// 00649110  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00649114  8b542404             mov edx, dword ptr [esp + 4]
// 00649118  56                   push esi
// 00649119  50                   push eax
// 0064911a  8b4204               mov eax, dword ptr [edx + 4]
// 0064911d  8bf1                 mov esi, ecx
// 0064911f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00649123  51                   push ecx
// 00649124  50                   push eax
// 00649125  ff1514d17700         call dword ptr [0x77d114]
// 0064912b  50                   push eax
// 0064912c  8bce                 mov ecx, esi
// 0064912e  e80571feff           call 0x630238
// 00649133  5e                   pop esi
// 00649134  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\winfrm.cpp (function ?CreateCompatibleBitmap@CBitmap@@QAEHPAVCDC@@HH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winfrm.cpp
