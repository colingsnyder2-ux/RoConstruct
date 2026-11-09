// from server: 100% by auto
// roc 2007-03 004017d0  unit: seg_00400000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004017d0
//
// 004017d0  56                   push esi
// 004017d1  8b742408             mov esi, dword ptr [esp + 8]
// 004017d5  85f6                 test esi, esi
// 004017d7  742d                 je 0x401806
// 004017d9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004017dd  85c0                 test eax, eax
// 004017df  7425                 je 0x401806
// 004017e1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004017e5  8b542414             mov edx, dword ptr [esp + 0x14]
// 004017e9  51                   push ecx
// 004017ea  56                   push esi
// 004017eb  6aff                 push -1
// 004017ed  50                   push eax
// 004017ee  6a00                 push 0
// 004017f0  52                   push edx
// 004017f1  66c7060000           mov word ptr [esi], 0
// 004017f6  ff15d8d27700         call dword ptr [0x77d2d8]
// 004017fc  f7d8                 neg eax
// 004017fe  1bc0                 sbb eax, eax
// 00401800  23c6                 and eax, esi
// 00401802  5e                   pop esi
// 00401803  c21000               ret 0x10
// 00401806  33c0                 xor eax, eax
// 00401808  5e                   pop esi
// 00401809  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
