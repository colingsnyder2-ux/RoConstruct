// from server: 100% by auto
// roc 2009-12 00804960  unit: CXTPCommandBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00804960
//
// 00804960  8b442410             mov eax, dword ptr [esp + 0x10]
// 00804964  8b542408             mov edx, dword ptr [esp + 8]
// 00804968  56                   push esi
// 00804969  50                   push eax
// 0080496a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0080496e  8bf1                 mov esi, ecx
// 00804970  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00804974  51                   push ecx
// 00804975  52                   push edx
// 00804976  50                   push eax
// 00804977  ff150cb19800         call dword ptr [0x98b10c]
// 0080497d  50                   push eax
// 0080497e  8bce                 mov ecx, esi
// 00804980  e8a5f4feff           call 0x7f3e2a
// 00804985  5e                   pop esi
// 00804986  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\dlgfnt.cpp (function ?CreateDCA@CDC@@QAEHPBD00PBX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgfnt.cpp
