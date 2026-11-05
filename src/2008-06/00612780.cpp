// from server: 100% by auto
// roc 2008-06 00612780  unit: seg_00610000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612780
//
// 00612780  8b442408             mov eax, dword ptr [esp + 8]
// 00612784  53                   push ebx
// 00612785  56                   push esi
// 00612786  57                   push edi
// 00612787  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061278b  8bcf                 mov ecx, edi
// 0061278d  e8fef2ffff           call 0x611a90
// 00612792  8b7708               mov esi, dword ptr [edi + 8]
// 00612795  8bd8                 mov ebx, eax
// 00612797  8b442418             mov eax, dword ptr [esp + 0x18]
// 0061279b  8b0b                 mov ecx, dword ptr [ebx]
// 0061279d  50                   push eax
// 0061279e  51                   push ecx
// 0061279f  57                   push edi
// 006127a0  83ee10               sub esi, 0x10
// 006127a3  e818c40400           call 0x65ebc0
// 006127a8  8b16                 mov edx, dword ptr [esi]
// 006127aa  8910                 mov dword ptr [eax], edx
// 006127ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 006127af  894804               mov dword ptr [eax + 4], ecx
// 006127b2  8b5608               mov edx, dword ptr [esi + 8]
// 006127b5  895008               mov dword ptr [eax + 8], edx
// 006127b8  8b4708               mov eax, dword ptr [edi + 8]
// 006127bb  b904000000           mov ecx, 4
// 006127c0  83c40c               add esp, 0xc
// 006127c3  3948f8               cmp dword ptr [eax - 8], ecx
// 006127c6  7c1a                 jl 0x6127e2
// 006127c8  8b40f0               mov eax, dword ptr [eax - 0x10]
// 006127cb  f6400503             test byte ptr [eax + 5], 3
// 006127cf  7411                 je 0x6127e2
// 006127d1  8b1b                 mov ebx, dword ptr [ebx]
// 006127d3  844b05               test byte ptr [ebx + 5], cl
// 006127d6  740a                 je 0x6127e2
// 006127d8  53                   push ebx
// 006127d9  57                   push edi
// 006127da  e8e19c0400           call 0x65c4c0
// 006127df  83c408               add esp, 8
// 006127e2  834708f0             add dword ptr [edi + 8], -0x10
// 006127e6  5f                   pop edi
// 006127e7  5e                   pop esi
// 006127e8  5b                   pop ebx
// 006127e9  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
