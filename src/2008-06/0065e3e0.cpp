// from server: 100% by auto
// roc 2008-06 0065e3e0  unit: seg_00650000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e3e0
//
// 0065e3e0  dd442404             fld qword ptr [esp + 4]
// 0065e3e4  8a4e07               mov cl, byte ptr [esi + 7]
// 0065e3e7  dc0538128100         fadd qword ptr [0x811238]
// 0065e3ed  57                   push edi
// 0065e3ee  bf01000000           mov edi, 1
// 0065e3f3  d3e7                 shl edi, cl
// 0065e3f5  dd5c2408             fstp qword ptr [esp + 8]
// 0065e3f9  8b442408             mov eax, dword ptr [esp + 8]
// 0065e3fd  0344240c             add eax, dword ptr [esp + 0xc]
// 0065e401  33d2                 xor edx, edx
// 0065e403  4f                   dec edi
// 0065e404  83cf01               or edi, 1
// 0065e407  f7f7                 div edi
// 0065e409  5f                   pop edi
// 0065e40a  8bc2                 mov eax, edx
// 0065e40c  c1e005               shl eax, 5
// 0065e40f  034610               add eax, dword ptr [esi + 0x10]
// 0065e412  c3                   ret 
// library lua-5.1/ltable.c (function _hashnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
