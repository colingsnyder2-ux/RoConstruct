// from server: 100% by auto
// roc 2008-06 00621ec0  unit: lua_exception  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621ec0
//
// 00621ec0  56                   push esi
// 00621ec1  8b742408             mov esi, dword ptr [esp + 8]
// 00621ec5  66837e3400           cmp word ptr [esi + 0x34], 0
// 00621eca  760e                 jbe 0x621eda
// 00621ecc  68dc478400           push 0x8447dc
// 00621ed1  56                   push esi
// 00621ed2  e8f9180000           call 0x6237d0
// 00621ed7  83c408               add esp, 8
// 00621eda  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00621ede  8b4e08               mov ecx, dword ptr [esi + 8]
// 00621ee1  c1e004               shl eax, 4
// 00621ee4  2bc8                 sub ecx, eax
// 00621ee6  894e0c               mov dword ptr [esi + 0xc], ecx
// 00621ee9  c6460601             mov byte ptr [esi + 6], 1
// 00621eed  83c8ff               or eax, 0xffffffff
// 00621ef0  5e                   pop esi
// 00621ef1  c3                   ret 
// library lua-5.1.2/ldo.c (function _lua_yield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
