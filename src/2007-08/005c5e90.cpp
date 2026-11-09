// from server: 100% by auto
// roc 2007-08 005c5e90  unit: lua_exception  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5e90
//
// 005c5e90  56                   push esi
// 005c5e91  8b742408             mov esi, dword ptr [esp + 8]
// 005c5e95  66837e3400           cmp word ptr [esi + 0x34], 0
// 005c5e9a  760e                 jbe 0x5c5eaa
// 005c5e9c  688c967b00           push 0x7b968c
// 005c5ea1  56                   push esi
// 005c5ea2  e859110000           call 0x5c7000
// 005c5ea7  83c408               add esp, 8
// 005c5eaa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c5eae  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c5eb1  c1e004               shl eax, 4
// 005c5eb4  2bc8                 sub ecx, eax
// 005c5eb6  894e0c               mov dword ptr [esi + 0xc], ecx
// 005c5eb9  c6460601             mov byte ptr [esi + 6], 1
// 005c5ebd  83c8ff               or eax, 0xffffffff
// 005c5ec0  5e                   pop esi
// 005c5ec1  c3                   ret 
// library lua-5.1.2/ldo.c (function _lua_yield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
