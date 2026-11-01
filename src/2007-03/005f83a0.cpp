// from server: 100% by auto
// roc 2007-03 005f83a0  unit: seg_005f0000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f83a0
//
// 005f83a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005f83a4  33c0                 xor eax, eax
// 005f83a6  83f910               cmp ecx, 0x10
// 005f83a9  7212                 jb 0x5f83bd
// 005f83ab  eb03                 jmp 0x5f83b0
// 005f83ad  8d4900               lea ecx, [ecx]
// 005f83b0  83c101               add ecx, 1
// 005f83b3  d1e9                 shr ecx, 1
// 005f83b5  83c001               add eax, 1
// 005f83b8  83f910               cmp ecx, 0x10
// 005f83bb  73f3                 jae 0x5f83b0
// 005f83bd  83f908               cmp ecx, 8
// 005f83c0  7303                 jae 0x5f83c5
// 005f83c2  8bc1                 mov eax, ecx
// 005f83c4  c3                   ret 
// 005f83c5  8d04c508000000       lea eax, [eax*8 + 8]
// 005f83cc  83c1f8               add ecx, -8
// 005f83cf  0bc1                 or eax, ecx
// 005f83d1  c3                   ret 
// library lua-5.1.1/lobject.c (function _luaO_int2fb)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lobject.c
