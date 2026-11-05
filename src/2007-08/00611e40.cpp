// from server: 100% by auto
// roc 2007-08 00611e40  unit: seg_00610000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00611e40
//
// 00611e40  dd442404             fld qword ptr [esp + 4]
// 00611e44  8a4e07               mov cl, byte ptr [esi + 7]
// 00611e47  dc0598317900         fadd qword ptr [0x793198]
// 00611e4d  57                   push edi
// 00611e4e  bf01000000           mov edi, 1
// 00611e53  d3e7                 shl edi, cl
// 00611e55  dd5c2408             fstp qword ptr [esp + 8]
// 00611e59  8b442408             mov eax, dword ptr [esp + 8]
// 00611e5d  0344240c             add eax, dword ptr [esp + 0xc]
// 00611e61  33d2                 xor edx, edx
// 00611e63  83ef01               sub edi, 1
// 00611e66  83cf01               or edi, 1
// 00611e69  f7f7                 div edi
// 00611e6b  5f                   pop edi
// 00611e6c  8bc2                 mov eax, edx
// 00611e6e  c1e005               shl eax, 5
// 00611e71  034610               add eax, dword ptr [esi + 0x10]
// 00611e74  c3                   ret 
// library lua-5.1/ltable.c (function _hashnum)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
