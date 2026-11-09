// from server: 100% by auto
// roc 2007-08 00643e10  unit: CXTPCommandBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00643e10
//
// 00643e10  8b442410             mov eax, dword ptr [esp + 0x10]
// 00643e14  8b542408             mov edx, dword ptr [esp + 8]
// 00643e18  56                   push esi
// 00643e19  50                   push eax
// 00643e1a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00643e1e  8bf1                 mov esi, ecx
// 00643e20  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00643e24  51                   push ecx
// 00643e25  52                   push edx
// 00643e26  50                   push eax
// 00643e27  ff1524d17700         call dword ptr [0x77d124]
// 00643e2d  50                   push eax
// 00643e2e  8bce                 mov ecx, esi
// 00643e30  e803c4feff           call 0x630238
// 00643e35  5e                   pop esi
// 00643e36  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\dlgfnt.cpp (function ?CreateDCA@CDC@@QAEHPBD00PBX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgfnt.cpp
