// from server: 100% by auto
// roc 2012-06 00832810  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832810
//
// 00832810  8b442408             mov eax, dword ptr [esp + 8]
// 00832814  56                   push esi
// 00832815  8b742408             mov esi, dword ptr [esp + 8]
// 00832819  8b4e08               mov ecx, dword ptr [esi + 8]
// 0083281c  57                   push edi
// 0083281d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00832821  40                   inc eax
// 00832822  c1e004               shl eax, 4
// 00832825  57                   push edi
// 00832826  2bc8                 sub ecx, eax
// 00832828  51                   push ecx
// 00832829  56                   push esi
// 0083282a  e801270200           call 0x854f30
// 0083282f  83c40c               add esp, 0xc
// 00832832  83ffff               cmp edi, -1
// 00832835  750e                 jne 0x832845
// 00832837  8b4614               mov eax, dword ptr [esi + 0x14]
// 0083283a  8b7608               mov esi, dword ptr [esi + 8]
// 0083283d  3b7008               cmp esi, dword ptr [eax + 8]
// 00832840  7203                 jb 0x832845
// 00832842  897008               mov dword ptr [eax + 8], esi
// 00832845  5f                   pop edi
// 00832846  5e                   pop esi
// 00832847  c3                   ret 
// library lua-5.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
