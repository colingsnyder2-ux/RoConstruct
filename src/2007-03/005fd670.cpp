// from server: 100% by auto
// roc 2007-03 005fd670  unit: seg_005f0000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd670
//
// 005fd670  8b4030               mov eax, dword ptr [eax + 0x30]
// 005fd673  005032               add byte ptr [eax + 0x32], dl
// 005fd676  85d2                 test edx, edx
// 005fd678  742a                 je 0x5fd6a4
// 005fd67a  56                   push esi
// 005fd67b  57                   push edi
// 005fd67c  8d642400             lea esp, [esp]
// 005fd680  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 005fd684  8b30                 mov esi, dword ptr [eax]
// 005fd686  8b7618               mov esi, dword ptr [esi + 0x18]
// 005fd689  8b7818               mov edi, dword ptr [eax + 0x18]
// 005fd68c  2bca                 sub ecx, edx
// 005fd68e  83ea01               sub edx, 1
// 005fd691  0fb78c48ac000000     movzx ecx, word ptr [eax + ecx*2 + 0xac]
// 005fd699  8d0c49               lea ecx, [ecx + ecx*2]
// 005fd69c  897c8e04             mov dword ptr [esi + ecx*4 + 4], edi
// 005fd6a0  75de                 jne 0x5fd680
// 005fd6a2  5f                   pop edi
// 005fd6a3  5e                   pop esi
// 005fd6a4  c3                   ret 
// library lua-5.1.1/lparser.c (function _adjustlocalvars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
