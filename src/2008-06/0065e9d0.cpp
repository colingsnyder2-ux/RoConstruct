// from server: 100% by auto
// roc 2008-06 0065e9d0  unit: seg_00650000  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e9d0
//
// 0065e9d0  8b442408             mov eax, dword ptr [esp + 8]
// 0065e9d4  83ec08               sub esp, 8
// 0065e9d7  56                   push esi
// 0065e9d8  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065e9dc  8d48ff               lea ecx, [eax - 1]
// 0065e9df  3b4e1c               cmp ecx, dword ptr [esi + 0x1c]
// 0065e9e2  730f                 jae 0x65e9f3
// 0065e9e4  8b560c               mov edx, dword ptr [esi + 0xc]
// 0065e9e7  c1e004               shl eax, 4
// 0065e9ea  8d4402f0             lea eax, [edx + eax - 0x10]
// 0065e9ee  5e                   pop esi
// 0065e9ef  83c408               add esp, 8
// 0065e9f2  c3                   ret 
// 0065e9f3  db442414             fild dword ptr [esp + 0x14]
// 0065e9f7  8a4e07               mov cl, byte ptr [esi + 7]
// 0065e9fa  dd0538128100         fld qword ptr [0x811238]
// 0065ea00  57                   push edi
// 0065ea01  bf01000000           mov edi, 1
// 0065ea06  d3e7                 shl edi, cl
// 0065ea08  d8c1                 fadd st(1)
// 0065ea0a  33d2                 xor edx, edx
// 0065ea0c  b903000000           mov ecx, 3
// 0065ea11  dd5c2408             fstp qword ptr [esp + 8]
// 0065ea15  8b442408             mov eax, dword ptr [esp + 8]
// 0065ea19  0344240c             add eax, dword ptr [esp + 0xc]
// 0065ea1d  4f                   dec edi
// 0065ea1e  83cf01               or edi, 1
// 0065ea21  f7f7                 div edi
// 0065ea23  5f                   pop edi
// 0065ea24  c1e205               shl edx, 5
// 0065ea27  035610               add edx, dword ptr [esi + 0x10]
// 0065ea2a  394a18               cmp dword ptr [edx + 0x18], ecx
// 0065ea2d  750a                 jne 0x65ea39
// 0065ea2f  dc5210               fcom qword ptr [edx + 0x10]
// 0065ea32  dfe0                 fnstsw ax
// 0065ea34  f6c444               test ah, 0x44
// 0065ea37  7b13                 jnp 0x65ea4c
// 0065ea39  8b521c               mov edx, dword ptr [edx + 0x1c]
// 0065ea3c  85d2                 test edx, edx
// 0065ea3e  75ea                 jne 0x65ea2a
// 0065ea40  b880488400           mov eax, 0x844880
// 0065ea45  ddd8                 fstp st(0)
// 0065ea47  5e                   pop esi
// 0065ea48  83c408               add esp, 8
// 0065ea4b  c3                   ret 
// 0065ea4c  8bc2                 mov eax, edx
// 0065ea4e  ddd8                 fstp st(0)
// 0065ea50  5e                   pop esi
// 0065ea51  83c408               add esp, 8
// 0065ea54  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_getnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
