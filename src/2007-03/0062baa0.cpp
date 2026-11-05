// from server: 100% by auto
// roc 2007-03 0062baa0  unit: seg_00620000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062baa0
//
// 0062baa0  56                   push esi
// 0062baa1  57                   push edi
// 0062baa2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0062baa6  85ff                 test edi, edi
// 0062baa8  8bf1                 mov esi, ecx
// 0062baaa  7d05                 jge 0x62bab1
// 0062baac  e8fd28ffff           call 0x61e3ae
// 0062bab1  3b7e08               cmp edi, dword ptr [esi + 8]
// 0062bab4  7c0b                 jl 0x62bac1
// 0062bab6  6aff                 push -1
// 0062bab8  8d4701               lea eax, [edi + 1]
// 0062babb  50                   push eax
// 0062babc  e85ff7e2ff           call 0x45b220
// 0062bac1  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062bac4  8b542410             mov edx, dword ptr [esp + 0x10]
// 0062bac8  8914b9               mov dword ptr [ecx + edi*4], edx
// 0062bacb  5f                   pop edi
// 0062bacc  5e                   pop esi
// 0062bacd  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\array_d.cpp (function ?SetAtGrow@CDWordArray@@QAEXHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_d.cpp
