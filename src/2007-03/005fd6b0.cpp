// from server: 100% by auto
// roc 2007-03 005fd6b0  unit: seg_005f0000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd6b0
//
// 005fd6b0  8b4030               mov eax, dword ptr [eax + 0x30]
// 005fd6b3  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 005fd6b7  3bca                 cmp ecx, edx
// 005fd6b9  7e2e                 jle 0x5fd6e9
// 005fd6bb  56                   push esi
// 005fd6bc  57                   push edi
// 005fd6bd  8d4900               lea ecx, [ecx]
// 005fd6c0  804032ff             add byte ptr [eax + 0x32], 0xff
// 005fd6c4  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 005fd6c8  0fb78c48ac000000     movzx ecx, word ptr [eax + ecx*2 + 0xac]
// 005fd6d0  8b30                 mov esi, dword ptr [eax]
// 005fd6d2  8b7618               mov esi, dword ptr [esi + 0x18]
// 005fd6d5  8b7818               mov edi, dword ptr [eax + 0x18]
// 005fd6d8  8d0c49               lea ecx, [ecx + ecx*2]
// 005fd6db  897c8e08             mov dword ptr [esi + ecx*4 + 8], edi
// 005fd6df  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 005fd6e3  3bca                 cmp ecx, edx
// 005fd6e5  7fd9                 jg 0x5fd6c0
// 005fd6e7  5f                   pop edi
// 005fd6e8  5e                   pop esi
// 005fd6e9  c3                   ret 
// library lua-5.1.1/lparser.c (function _removevars)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
