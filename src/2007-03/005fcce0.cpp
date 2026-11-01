// from server: 100% by auto
// roc 2007-03 005fcce0  unit: seg_005f0000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fcce0
//
// 005fcce0  56                   push esi
// 005fcce1  8b742408             mov esi, dword ptr [esp + 8]
// 005fcce5  833e00               cmp dword ptr [esi], 0
// 005fcce8  7547                 jne 0x5fcd31
// 005fccea  8b560c               mov edx, dword ptr [esi + 0xc]
// 005fcced  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fccf0  8d4c2408             lea ecx, [esp + 8]
// 005fccf4  51                   push ecx
// 005fccf5  52                   push edx
// 005fccf6  50                   push eax
// 005fccf7  8b4608               mov eax, dword ptr [esi + 8]
// 005fccfa  ffd0                 call eax
// 005fccfc  83c40c               add esp, 0xc
// 005fccff  85c0                 test eax, eax
// 005fcd01  741e                 je 0x5fcd21
// 005fcd03  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005fcd07  85c9                 test ecx, ecx
// 005fcd09  7416                 je 0x5fcd21
// 005fcd0b  83c1ff               add ecx, -1
// 005fcd0e  894604               mov dword ptr [esi + 4], eax
// 005fcd11  890e                 mov dword ptr [esi], ecx
// 005fcd13  0fb610               movzx edx, byte ptr [eax]
// 005fcd16  83c001               add eax, 1
// 005fcd19  83faff               cmp edx, -1
// 005fcd1c  894604               mov dword ptr [esi + 4], eax
// 005fcd1f  7505                 jne 0x5fcd26
// 005fcd21  83c8ff               or eax, 0xffffffff
// 005fcd24  5e                   pop esi
// 005fcd25  c3                   ret 
// 005fcd26  83c101               add ecx, 1
// 005fcd29  83c0ff               add eax, -1
// 005fcd2c  890e                 mov dword ptr [esi], ecx
// 005fcd2e  894604               mov dword ptr [esi + 4], eax
// 005fcd31  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fcd34  0fb601               movzx eax, byte ptr [ecx]
// 005fcd37  5e                   pop esi
// 005fcd38  c3                   ret 
// library lua-5.1.1/lzio.c (function _luaZ_lookahead)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lzio.c
