// from server: 100% by auto
// roc 2008-06 00612980  unit: seg_00610000  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612980
//
// 00612980  8b442410             mov eax, dword ptr [esp + 0x10]
// 00612984  83ec08               sub esp, 8
// 00612987  56                   push esi
// 00612988  8b742410             mov esi, dword ptr [esp + 0x10]
// 0061298c  85c0                 test eax, eax
// 0061298e  7504                 jne 0x612994
// 00612990  33c9                 xor ecx, ecx
// 00612992  eb0c                 jmp 0x6129a0
// 00612994  8bce                 mov ecx, esi
// 00612996  e8f5f0ffff           call 0x611a90
// 0061299b  2b4620               sub eax, dword ptr [esi + 0x20]
// 0061299e  8bc8                 mov ecx, eax
// 006129a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006129a4  40                   inc eax
// 006129a5  c1e004               shl eax, 4
// 006129a8  8bd0                 mov edx, eax
// 006129aa  8b4608               mov eax, dword ptr [esi + 8]
// 006129ad  57                   push edi
// 006129ae  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006129b2  2bc2                 sub eax, edx
// 006129b4  89442408             mov dword ptr [esp + 8], eax
// 006129b8  2b4620               sub eax, dword ptr [esi + 0x20]
// 006129bb  51                   push ecx
// 006129bc  50                   push eax
// 006129bd  8d442410             lea eax, [esp + 0x10]
// 006129c1  50                   push eax
// 006129c2  6860296100           push 0x612960
// 006129c7  56                   push esi
// 006129c8  897c2420             mov dword ptr [esp + 0x20], edi
// 006129cc  e8affa0000           call 0x622480
// 006129d1  83c414               add esp, 0x14
// 006129d4  83ffff               cmp edi, -1
// 006129d7  5f                   pop edi
// 006129d8  750e                 jne 0x6129e8
// 006129da  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006129dd  8b7608               mov esi, dword ptr [esi + 8]
// 006129e0  3b7108               cmp esi, dword ptr [ecx + 8]
// 006129e3  7203                 jb 0x6129e8
// 006129e5  897108               mov dword ptr [ecx + 8], esi
// 006129e8  5e                   pop esi
// 006129e9  83c408               add esp, 8
// 006129ec  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
