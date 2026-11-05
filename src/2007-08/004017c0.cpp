// from server: 100% by auto
// roc 2007-08 004017c0  unit: CAboutRobloxDialog  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004017c0
//
// 004017c0  56                   push esi
// 004017c1  8b742408             mov esi, dword ptr [esp + 8]
// 004017c5  85f6                 test esi, esi
// 004017c7  742d                 je 0x4017f6
// 004017c9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004017cd  85c0                 test eax, eax
// 004017cf  7425                 je 0x4017f6
// 004017d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004017d5  8b542414             mov edx, dword ptr [esp + 0x14]
// 004017d9  51                   push ecx
// 004017da  56                   push esi
// 004017db  6aff                 push -1
// 004017dd  50                   push eax
// 004017de  6a00                 push 0
// 004017e0  52                   push edx
// 004017e1  66c7060000           mov word ptr [esi], 0
// 004017e6  ff1518d37700         call dword ptr [0x77d318]
// 004017ec  f7d8                 neg eax
// 004017ee  1bc0                 sbb eax, eax
// 004017f0  23c6                 and eax, esi
// 004017f2  5e                   pop esi
// 004017f3  c21000               ret 0x10
// 004017f6  33c0                 xor eax, eax
// 004017f8  5e                   pop esi
// 004017f9  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
