// from server: 100% by auto
// roc 2007-03 006391a0  unit: seg_00630000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006391a0
//
// 006391a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006391a4  8b542408             mov edx, dword ptr [esp + 8]
// 006391a8  56                   push esi
// 006391a9  50                   push eax
// 006391aa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006391ae  8bf1                 mov esi, ecx
// 006391b0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006391b4  51                   push ecx
// 006391b5  52                   push edx
// 006391b6  50                   push eax
// 006391b7  ff1524d17700         call dword ptr [0x77d124]
// 006391bd  50                   push eax
// 006391be  8bce                 mov ecx, esi
// 006391c0  e80155feff           call 0x61e6c6
// 006391c5  5e                   pop esi
// 006391c6  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\dlgfnt.cpp (function ?CreateDCA@CDC@@QAEHPBD00PBX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgfnt.cpp
