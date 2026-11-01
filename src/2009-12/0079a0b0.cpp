// from server: 100% by auto
// roc 2009-12 0079a0b0  unit: lua_exception  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a0b0
//
// 0079a0b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0079a0b4  33c0                 xor eax, eax
// 0079a0b6  83f910               cmp ecx, 0x10
// 0079a0b9  720e                 jb 0x79a0c9
// 0079a0bb  eb03                 jmp 0x79a0c0
// 0079a0bd  8d4900               lea ecx, [ecx]
// 0079a0c0  41                   inc ecx
// 0079a0c1  d1e9                 shr ecx, 1
// 0079a0c3  40                   inc eax
// 0079a0c4  83f910               cmp ecx, 0x10
// 0079a0c7  73f7                 jae 0x79a0c0
// 0079a0c9  83f908               cmp ecx, 8
// 0079a0cc  7303                 jae 0x79a0d1
// 0079a0ce  8bc1                 mov eax, ecx
// 0079a0d0  c3                   ret 
// 0079a0d1  8d04c508000000       lea eax, [eax*8 + 8]
// 0079a0d8  83c1f8               add ecx, -8
// 0079a0db  0bc1                 or eax, ecx
// 0079a0dd  c3                   ret 
// library lua-5.1/lobject.c (function _luaO_int2fb)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
