// from server: 100% by auto
// roc 2007-03 005fbdf0  unit: seg_005f0000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbdf0
//
// 005fbdf0  8b442408             mov eax, dword ptr [esp + 8]
// 005fbdf4  83ec08               sub esp, 8
// 005fbdf7  56                   push esi
// 005fbdf8  8b742410             mov esi, dword ptr [esp + 0x10]
// 005fbdfc  8d48ff               lea ecx, [eax - 1]
// 005fbdff  3b4e1c               cmp ecx, dword ptr [esi + 0x1c]
// 005fbe02  730f                 jae 0x5fbe13
// 005fbe04  8b560c               mov edx, dword ptr [esi + 0xc]
// 005fbe07  c1e004               shl eax, 4
// 005fbe0a  8d4402f0             lea eax, [edx + eax - 0x10]
// 005fbe0e  5e                   pop esi
// 005fbe0f  83c408               add esp, 8
// 005fbe12  c3                   ret 
// 005fbe13  db442414             fild dword ptr [esp + 0x14]
// 005fbe17  8a4e07               mov cl, byte ptr [esi + 7]
// 005fbe1a  dd05a81f7900         fld qword ptr [0x791fa8]
// 005fbe20  57                   push edi
// 005fbe21  bf01000000           mov edi, 1
// 005fbe26  d3e7                 shl edi, cl
// 005fbe28  d8c1                 fadd st(1)
// 005fbe2a  33d2                 xor edx, edx
// 005fbe2c  b903000000           mov ecx, 3
// 005fbe31  dd5c2408             fstp qword ptr [esp + 8]
// 005fbe35  8b442408             mov eax, dword ptr [esp + 8]
// 005fbe39  0344240c             add eax, dword ptr [esp + 0xc]
// 005fbe3d  83ef01               sub edi, 1
// 005fbe40  83cf01               or edi, 1
// 005fbe43  f7f7                 div edi
// 005fbe45  5f                   pop edi
// 005fbe46  c1e205               shl edx, 5
// 005fbe49  035610               add edx, dword ptr [esi + 0x10]
// 005fbe4c  394a18               cmp dword ptr [edx + 0x18], ecx
// 005fbe4f  750a                 jne 0x5fbe5b
// 005fbe51  dc5210               fcom qword ptr [edx + 0x10]
// 005fbe54  dfe0                 fnstsw ax
// 005fbe56  f6c444               test ah, 0x44
// 005fbe59  7b13                 jnp 0x5fbe6e
// 005fbe5b  8b521c               mov edx, dword ptr [edx + 0x1c]
// 005fbe5e  85d2                 test edx, edx
// 005fbe60  75ea                 jne 0x5fbe4c
// 005fbe62  b8a0007c00           mov eax, 0x7c00a0
// 005fbe67  ddd8                 fstp st(0)
// 005fbe69  5e                   pop esi
// 005fbe6a  83c408               add esp, 8
// 005fbe6d  c3                   ret 
// 005fbe6e  8bc2                 mov eax, edx
// 005fbe70  ddd8                 fstp st(0)
// 005fbe72  5e                   pop esi
// 005fbe73  83c408               add esp, 8
// 005fbe76  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_getnum)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
