// from server: 100% by auto
// roc 2009-12 007976b0  unit: lua_exception  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007976b0
//
// 007976b0  56                   push esi
// 007976b1  8b742408             mov esi, dword ptr [esp + 8]
// 007976b5  668b4634             mov ax, word ptr [esi + 0x34]
// 007976b9  663b4636             cmp ax, word ptr [esi + 0x36]
// 007976bd  760e                 jbe 0x7976cd
// 007976bf  68a0a99e00           push 0x9ea9a0
// 007976c4  56                   push esi
// 007976c5  e8763c0000           call 0x79b340
// 007976ca  83c408               add esp, 8
// 007976cd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007976d1  8b5608               mov edx, dword ptr [esi + 8]
// 007976d4  c1e104               shl ecx, 4
// 007976d7  2bd1                 sub edx, ecx
// 007976d9  89560c               mov dword ptr [esi + 0xc], edx
// 007976dc  c6460601             mov byte ptr [esi + 6], 1
// 007976e0  83c8ff               or eax, 0xffffffff
// 007976e3  5e                   pop esi
// 007976e4  c3                   ret 
// library lua-5.1.3/ldo.c (function _lua_yield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldo.c
