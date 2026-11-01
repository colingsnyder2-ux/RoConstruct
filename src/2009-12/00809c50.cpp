// from server: 100% by auto
// roc 2009-12 00809c50  unit: CXTPCommandBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809c50
//
// 00809c50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00809c54  8b542404             mov edx, dword ptr [esp + 4]
// 00809c58  56                   push esi
// 00809c59  50                   push eax
// 00809c5a  8b4204               mov eax, dword ptr [edx + 4]
// 00809c5d  8bf1                 mov esi, ecx
// 00809c5f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00809c63  51                   push ecx
// 00809c64  50                   push eax
// 00809c65  ff1550b19800         call dword ptr [0x98b150]
// 00809c6b  50                   push eax
// 00809c6c  8bce                 mov ecx, esi
// 00809c6e  e8b7a1feff           call 0x7f3e2a
// 00809c73  5e                   pop esi
// 00809c74  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\winfrm.cpp (function ?CreateCompatibleBitmap@CBitmap@@QAEHPAVCDC@@HH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winfrm.cpp
