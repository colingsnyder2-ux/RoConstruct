// from server: 100% by auto
// roc 2007-08 00612440  unit: seg_00610000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612440
//
// 00612440  8b442408             mov eax, dword ptr [esp + 8]
// 00612444  83ec08               sub esp, 8
// 00612447  56                   push esi
// 00612448  8b742410             mov esi, dword ptr [esp + 0x10]
// 0061244c  8d48ff               lea ecx, [eax - 1]
// 0061244f  3b4e1c               cmp ecx, dword ptr [esi + 0x1c]
// 00612452  730f                 jae 0x612463
// 00612454  8b560c               mov edx, dword ptr [esi + 0xc]
// 00612457  c1e004               shl eax, 4
// 0061245a  8d4402f0             lea eax, [edx + eax - 0x10]
// 0061245e  5e                   pop esi
// 0061245f  83c408               add esp, 8
// 00612462  c3                   ret 
// 00612463  db442414             fild dword ptr [esp + 0x14]
// 00612467  8a4e07               mov cl, byte ptr [esi + 7]
// 0061246a  dd0598317900         fld qword ptr [0x793198]
// 00612470  57                   push edi
// 00612471  bf01000000           mov edi, 1
// 00612476  d3e7                 shl edi, cl
// 00612478  d8c1                 fadd st(1)
// 0061247a  33d2                 xor edx, edx
// 0061247c  b903000000           mov ecx, 3
// 00612481  dd5c2408             fstp qword ptr [esp + 8]
// 00612485  8b442408             mov eax, dword ptr [esp + 8]
// 00612489  0344240c             add eax, dword ptr [esp + 0xc]
// 0061248d  83ef01               sub edi, 1
// 00612490  83cf01               or edi, 1
// 00612493  f7f7                 div edi
// 00612495  5f                   pop edi
// 00612496  c1e205               shl edx, 5
// 00612499  035610               add edx, dword ptr [esi + 0x10]
// 0061249c  394a18               cmp dword ptr [edx + 0x18], ecx
// 0061249f  750a                 jne 0x6124ab
// 006124a1  dc5210               fcom qword ptr [edx + 0x10]
// 006124a4  dfe0                 fnstsw ax
// 006124a6  f6c444               test ah, 0x44
// 006124a9  7b13                 jnp 0x6124be
// 006124ab  8b521c               mov edx, dword ptr [edx + 0x1c]
// 006124ae  85d2                 test edx, edx
// 006124b0  75ea                 jne 0x61249c
// 006124b2  b8e82f7c00           mov eax, 0x7c2fe8
// 006124b7  ddd8                 fstp st(0)
// 006124b9  5e                   pop esi
// 006124ba  83c408               add esp, 8
// 006124bd  c3                   ret 
// 006124be  8bc2                 mov eax, edx
// 006124c0  ddd8                 fstp st(0)
// 006124c2  5e                   pop esi
// 006124c3  83c408               add esp, 8
// 006124c6  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_getnum)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
