// from server: 100% by auto
// roc 2007-03 00625ab0  unit: seg_00620000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625ab0
//
// 00625ab0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00625ab4  8b542404             mov edx, dword ptr [esp + 4]
// 00625ab8  56                   push esi
// 00625ab9  50                   push eax
// 00625aba  8b4204               mov eax, dword ptr [edx + 4]
// 00625abd  8bf1                 mov esi, ecx
// 00625abf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00625ac3  51                   push ecx
// 00625ac4  50                   push eax
// 00625ac5  ff15ecd07700         call dword ptr [0x77d0ec]
// 00625acb  50                   push eax
// 00625acc  8bce                 mov ecx, esi
// 00625ace  e8f38bffff           call 0x61e6c6
// 00625ad3  5e                   pop esi
// 00625ad4  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\winfrm.cpp (function ?CreateCompatibleBitmap@CBitmap@@QAEHPAVCDC@@HH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winfrm.cpp
