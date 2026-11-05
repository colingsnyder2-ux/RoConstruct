// from server: 100% by auto
// roc 2008-06 006126b0  unit: seg_00610000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006126b0
//
// 006126b0  8b442408             mov eax, dword ptr [esp + 8]
// 006126b4  83ec10               sub esp, 0x10
// 006126b7  53                   push ebx
// 006126b8  56                   push esi
// 006126b9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006126bd  57                   push edi
// 006126be  8bce                 mov ecx, esi
// 006126c0  e8cbf3ffff           call 0x611a90
// 006126c5  8b542428             mov edx, dword ptr [esp + 0x28]
// 006126c9  8bf8                 mov edi, eax
// 006126cb  8bc2                 mov eax, edx
// 006126cd  8d5801               lea ebx, [eax + 1]
// 006126d0  8a08                 mov cl, byte ptr [eax]
// 006126d2  40                   inc eax
// 006126d3  84c9                 test cl, cl
// 006126d5  75f9                 jne 0x6126d0
// 006126d7  2bc3                 sub eax, ebx
// 006126d9  50                   push eax
// 006126da  52                   push edx
// 006126db  56                   push esi
// 006126dc  e81fcc0400           call 0x65f300
// 006126e1  89442418             mov dword ptr [esp + 0x18], eax
// 006126e5  8b4608               mov eax, dword ptr [esi + 8]
// 006126e8  83e810               sub eax, 0x10
// 006126eb  50                   push eax
// 006126ec  8d4c241c             lea ecx, [esp + 0x1c]
// 006126f0  51                   push ecx
// 006126f1  57                   push edi
// 006126f2  56                   push esi
// 006126f3  c744243004000000     mov dword ptr [esp + 0x30], 4
// 006126fb  e8d0a20400           call 0x65c9d0
// 00612700  83c41c               add esp, 0x1c
// 00612703  834608f0             add dword ptr [esi + 8], -0x10
// 00612707  5f                   pop edi
// 00612708  5e                   pop esi
// 00612709  5b                   pop ebx
// 0061270a  83c410               add esp, 0x10
// 0061270d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
