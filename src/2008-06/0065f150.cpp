// from server: 100% by auto
// roc 2008-06 0065f150  unit: seg_00650000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065f150
//
// 0065f150  83ec10               sub esp, 0x10
// 0065f153  56                   push esi
// 0065f154  8b742420             mov esi, dword ptr [esp + 0x20]
// 0065f158  57                   push edi
// 0065f159  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0065f15d  56                   push esi
// 0065f15e  57                   push edi
// 0065f15f  e8fcf8ffff           call 0x65ea60
// 0065f164  83c408               add esp, 8
// 0065f167  3d80488400           cmp eax, 0x844880
// 0065f16c  751f                 jne 0x65f18d
// 0065f16e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065f172  8d442408             lea eax, [esp + 8]
// 0065f176  50                   push eax
// 0065f177  57                   push edi
// 0065f178  51                   push ecx
// 0065f179  89742414             mov dword ptr [esp + 0x14], esi
// 0065f17d  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 0065f185  e8d6feffff           call 0x65f060
// 0065f18a  83c40c               add esp, 0xc
// 0065f18d  5f                   pop edi
// 0065f18e  5e                   pop esi
// 0065f18f  83c410               add esp, 0x10
// 0065f192  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
