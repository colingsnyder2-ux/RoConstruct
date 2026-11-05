// from server: 100% by auto
// roc 2008-06 00612920  unit: seg_00610000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612920
//
// 00612920  8b442408             mov eax, dword ptr [esp + 8]
// 00612924  56                   push esi
// 00612925  8b742408             mov esi, dword ptr [esp + 8]
// 00612929  8b4e08               mov ecx, dword ptr [esi + 8]
// 0061292c  57                   push edi
// 0061292d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00612931  40                   inc eax
// 00612932  c1e004               shl eax, 4
// 00612935  57                   push edi
// 00612936  2bc8                 sub ecx, eax
// 00612938  51                   push ecx
// 00612939  56                   push esi
// 0061293a  e8c1f90000           call 0x622300
// 0061293f  83c40c               add esp, 0xc
// 00612942  83ffff               cmp edi, -1
// 00612945  750e                 jne 0x612955
// 00612947  8b4614               mov eax, dword ptr [esi + 0x14]
// 0061294a  8b7608               mov esi, dword ptr [esi + 8]
// 0061294d  3b7008               cmp esi, dword ptr [eax + 8]
// 00612950  7203                 jb 0x612955
// 00612952  897008               mov dword ptr [eax + 8], esi
// 00612955  5f                   pop edi
// 00612956  5e                   pop esi
// 00612957  c3                   ret 
// library lua-5.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
