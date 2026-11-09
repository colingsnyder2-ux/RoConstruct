// from server: 100% by auto
// roc 2009-12 007d1ab0  unit: seg_007d0000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1ab0
//
// 007d1ab0  8b4030               mov eax, dword ptr [eax + 0x30]
// 007d1ab3  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 007d1ab7  3bca                 cmp ecx, edx
// 007d1ab9  7e2d                 jle 0x7d1ae8
// 007d1abb  56                   push esi
// 007d1abc  57                   push edi
// 007d1abd  8d4900               lea ecx, [ecx]
// 007d1ac0  fe4832               dec byte ptr [eax + 0x32]
// 007d1ac3  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 007d1ac7  0fb78c48ac000000     movzx ecx, word ptr [eax + ecx*2 + 0xac]
// 007d1acf  8b30                 mov esi, dword ptr [eax]
// 007d1ad1  8b7618               mov esi, dword ptr [esi + 0x18]
// 007d1ad4  8b7818               mov edi, dword ptr [eax + 0x18]
// 007d1ad7  8d0c49               lea ecx, [ecx + ecx*2]
// 007d1ada  897c8e08             mov dword ptr [esi + ecx*4 + 8], edi
// 007d1ade  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 007d1ae2  3bca                 cmp ecx, edx
// 007d1ae4  7fda                 jg 0x7d1ac0
// 007d1ae6  5f                   pop edi
// 007d1ae7  5e                   pop esi
// 007d1ae8  c3                   ret 
// library lua-5.1/lparser.c (function _removevars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
