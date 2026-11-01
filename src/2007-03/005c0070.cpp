// from server: 100% by auto
// roc 2007-03 005c0070  unit: seg_005c0000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c0070
//
// 005c0070  56                   push esi
// 005c0071  8b742408             mov esi, dword ptr [esp + 8]
// 005c0075  66837e3400           cmp word ptr [esi + 0x34], 0
// 005c007a  760e                 jbe 0x5c008a
// 005c007c  681c977b00           push 0x7b971c
// 005c0081  56                   push esi
// 005c0082  e829300000           call 0x5c30b0
// 005c0087  83c408               add esp, 8
// 005c008a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c008e  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c0091  c1e004               shl eax, 4
// 005c0094  2bc8                 sub ecx, eax
// 005c0096  894e0c               mov dword ptr [esi + 0xc], ecx
// 005c0099  c6460601             mov byte ptr [esi + 6], 1
// 005c009d  83c8ff               or eax, 0xffffffff
// 005c00a0  5e                   pop esi
// 005c00a1  c3                   ret 
// library lua-5.1.1/ldo.c (function _lua_yield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
