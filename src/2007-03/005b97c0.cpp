// from server: 100% by auto
// roc 2007-03 005b97c0  unit: seg_005b0000  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b97c0
//
// 005b97c0  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b97c4  83ec08               sub esp, 8
// 005b97c7  85c0                 test eax, eax
// 005b97c9  56                   push esi
// 005b97ca  8b742410             mov esi, dword ptr [esp + 0x10]
// 005b97ce  7504                 jne 0x5b97d4
// 005b97d0  33c9                 xor ecx, ecx
// 005b97d2  eb0c                 jmp 0x5b97e0
// 005b97d4  8bce                 mov ecx, esi
// 005b97d6  e8d5f0ffff           call 0x5b88b0
// 005b97db  2b4620               sub eax, dword ptr [esi + 0x20]
// 005b97de  8bc8                 mov ecx, eax
// 005b97e0  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b97e4  83c001               add eax, 1
// 005b97e7  c1e004               shl eax, 4
// 005b97ea  8bd0                 mov edx, eax
// 005b97ec  8b4608               mov eax, dword ptr [esi + 8]
// 005b97ef  57                   push edi
// 005b97f0  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005b97f4  2bc2                 sub eax, edx
// 005b97f6  89442408             mov dword ptr [esp + 8], eax
// 005b97fa  2b4620               sub eax, dword ptr [esi + 0x20]
// 005b97fd  51                   push ecx
// 005b97fe  50                   push eax
// 005b97ff  8d442410             lea eax, [esp + 0x10]
// 005b9803  50                   push eax
// 005b9804  68a0975b00           push 0x5b97a0
// 005b9809  56                   push esi
// 005b980a  897c2420             mov dword ptr [esp + 0x20], edi
// 005b980e  e81d6e0000           call 0x5c0630
// 005b9813  83c414               add esp, 0x14
// 005b9816  83ffff               cmp edi, -1
// 005b9819  5f                   pop edi
// 005b981a  750e                 jne 0x5b982a
// 005b981c  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005b981f  8b7608               mov esi, dword ptr [esi + 8]
// 005b9822  3b7108               cmp esi, dword ptr [ecx + 8]
// 005b9825  7203                 jb 0x5b982a
// 005b9827  897108               mov dword ptr [ecx + 8], esi
// 005b982a  5e                   pop esi
// 005b982b  83c408               add esp, 8
// 005b982e  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
