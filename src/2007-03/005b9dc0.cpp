// from server: 100% by auto
// roc 2007-03 005b9dc0  unit: seg_005b0000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9dc0
//
// 005b9dc0  55                   push ebp
// 005b9dc1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 005b9dc5  56                   push esi
// 005b9dc6  be01000000           mov esi, 1
// 005b9dcb  397504               cmp dword ptr [ebp + 4], esi
// 005b9dce  7e63                 jle 0x5b9e33
// 005b9dd0  53                   push ebx
// 005b9dd1  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005b9dd4  57                   push edi
// 005b9dd5  6aff                 push -1
// 005b9dd7  53                   push ebx
// 005b9dd8  e8e3f0ffff           call 0x5b8ec0
// 005b9ddd  83c408               add esp, 8
// 005b9de0  89442414             mov dword ptr [esp + 0x14], eax
// 005b9de4  bffeffffff           mov edi, 0xfffffffe
// 005b9de9  8da42400000000       lea esp, [esp]
// 005b9df0  57                   push edi
// 005b9df1  53                   push ebx
// 005b9df2  e8c9f0ffff           call 0x5b8ec0
// 005b9df7  8b4d04               mov ecx, dword ptr [ebp + 4]
// 005b9dfa  8bd1                 mov edx, ecx
// 005b9dfc  2bd6                 sub edx, esi
// 005b9dfe  83c201               add edx, 1
// 005b9e01  83c408               add esp, 8
// 005b9e04  83fa0a               cmp edx, 0xa
// 005b9e07  7d06                 jge 0x5b9e0f
// 005b9e09  39442414             cmp dword ptr [esp + 0x14], eax
// 005b9e0d  760e                 jbe 0x5b9e1d
// 005b9e0f  01442414             add dword ptr [esp + 0x14], eax
// 005b9e13  83c601               add esi, 1
// 005b9e16  83ef01               sub edi, 1
// 005b9e19  3bf1                 cmp esi, ecx
// 005b9e1b  7cd3                 jl 0x5b9df0
// 005b9e1d  56                   push esi
// 005b9e1e  53                   push ebx
// 005b9e1f  e8dcfbffff           call 0x5b9a00
// 005b9e24  83c408               add esp, 8
// 005b9e27  b801000000           mov eax, 1
// 005b9e2c  2bc6                 sub eax, esi
// 005b9e2e  014504               add dword ptr [ebp + 4], eax
// 005b9e31  5f                   pop edi
// 005b9e32  5b                   pop ebx
// 005b9e33  5e                   pop esi
// 005b9e34  5d                   pop ebp
// 005b9e35  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _adjuststack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
