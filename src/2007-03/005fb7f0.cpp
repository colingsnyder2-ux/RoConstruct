// from server: 100% by auto
// roc 2007-03 005fb7f0  unit: seg_005f0000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fb7f0
//
// 005fb7f0  dd442404             fld qword ptr [esp + 4]
// 005fb7f4  8a4e07               mov cl, byte ptr [esi + 7]
// 005fb7f7  dc05a81f7900         fadd qword ptr [0x791fa8]
// 005fb7fd  57                   push edi
// 005fb7fe  bf01000000           mov edi, 1
// 005fb803  d3e7                 shl edi, cl
// 005fb805  dd5c2408             fstp qword ptr [esp + 8]
// 005fb809  8b442408             mov eax, dword ptr [esp + 8]
// 005fb80d  0344240c             add eax, dword ptr [esp + 0xc]
// 005fb811  33d2                 xor edx, edx
// 005fb813  83ef01               sub edi, 1
// 005fb816  83cf01               or edi, 1
// 005fb819  f7f7                 div edi
// 005fb81b  5f                   pop edi
// 005fb81c  8bc2                 mov eax, edx
// 005fb81e  c1e005               shl eax, 5
// 005fb821  034610               add eax, dword ptr [esi + 0x10]
// 005fb824  c3                   ret 
// library lua-5.1.1/ltable.c (function _hashnum)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
