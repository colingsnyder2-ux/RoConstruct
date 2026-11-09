// from server: 100% by auto
// roc 2007-08 006929e0  unit: CXTPStatusBar  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006929e0
//
// 006929e0  83ec10               sub esp, 0x10
// 006929e3  56                   push esi
// 006929e4  8d442404             lea eax, [esp + 4]
// 006929e8  50                   push eax
// 006929e9  8bf1                 mov esi, ecx
// 006929eb  ff1514ee7700         call dword ptr [0x77ee14]
// 006929f1  6a01                 push 1
// 006929f3  8d4c2408             lea ecx, [esp + 8]
// 006929f7  51                   push ecx
// 006929f8  8bce                 mov ecx, esi
// 006929fa  e8535f0a00           call 0x738952
// 006929ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00692a03  8b542404             mov edx, dword ptr [esp + 4]
// 00692a07  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00692a0b  0110                 add dword ptr [eax], edx
// 00692a0d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00692a11  015008               add dword ptr [eax + 8], edx
// 00692a14  83c1fe               add ecx, -2
// 00692a17  014804               add dword ptr [eax + 4], ecx
// 00692a1a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00692a1e  01480c               add dword ptr [eax + 0xc], ecx
// 00692a21  5e                   pop esi
// 00692a22  83c410               add esp, 0x10
// 00692a25  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcCalcSize@CStatusBar@@IAEXHPAUtagNCCALCSIZE_PARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
