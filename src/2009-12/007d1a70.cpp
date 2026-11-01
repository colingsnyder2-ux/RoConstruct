// from server: 100% by auto
// roc 2009-12 007d1a70  unit: seg_007d0000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1a70
//
// 007d1a70  8b4030               mov eax, dword ptr [eax + 0x30]
// 007d1a73  005032               add byte ptr [eax + 0x32], dl
// 007d1a76  85d2                 test edx, edx
// 007d1a78  742a                 je 0x7d1aa4
// 007d1a7a  56                   push esi
// 007d1a7b  57                   push edi
// 007d1a7c  8d642400             lea esp, [esp]
// 007d1a80  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 007d1a84  8b30                 mov esi, dword ptr [eax]
// 007d1a86  8b7618               mov esi, dword ptr [esi + 0x18]
// 007d1a89  8b7818               mov edi, dword ptr [eax + 0x18]
// 007d1a8c  2bca                 sub ecx, edx
// 007d1a8e  83ea01               sub edx, 1
// 007d1a91  0fb78c48ac000000     movzx ecx, word ptr [eax + ecx*2 + 0xac]
// 007d1a99  8d0c49               lea ecx, [ecx + ecx*2]
// 007d1a9c  897c8e04             mov dword ptr [esi + ecx*4 + 4], edi
// 007d1aa0  75de                 jne 0x7d1a80
// 007d1aa2  5f                   pop edi
// 007d1aa3  5e                   pop esi
// 007d1aa4  c3                   ret 
// library lua-5.1/lparser.c (function _adjustlocalvars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
