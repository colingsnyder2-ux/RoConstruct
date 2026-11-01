// from server: 100% by auto
// roc 2007-03 005fce70  unit: seg_005f0000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fce70
//
// 005fce70  51                   push ecx
// 005fce71  85c0                 test eax, eax
// 005fce73  57                   push edi
// 005fce74  7451                 je 0x5fcec7
// 005fce76  8d7810               lea edi, [eax + 0x10]
// 005fce79  85ff                 test edi, edi
// 005fce7b  744a                 je 0x5fcec7
// 005fce7d  8b400c               mov eax, dword ptr [eax + 0xc]
// 005fce80  83c001               add eax, 1
// 005fce83  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fce87  89442404             mov dword ptr [esp + 4], eax
// 005fce8b  7561                 jne 0x5fceee
// 005fce8d  8b4608               mov eax, dword ptr [esi + 8]
// 005fce90  8b16                 mov edx, dword ptr [esi]
// 005fce92  50                   push eax
// 005fce93  8b4604               mov eax, dword ptr [esi + 4]
// 005fce96  6a04                 push 4
// 005fce98  8d4c240c             lea ecx, [esp + 0xc]
// 005fce9c  51                   push ecx
// 005fce9d  52                   push edx
// 005fce9e  ffd0                 call eax
// 005fcea0  894610               mov dword ptr [esi + 0x10], eax
// 005fcea3  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fcea7  83c410               add esp, 0x10
// 005fceaa  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fceae  753e                 jne 0x5fceee
// 005fceb0  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fceb3  8b16                 mov edx, dword ptr [esi]
// 005fceb5  51                   push ecx
// 005fceb6  50                   push eax
// 005fceb7  8b4604               mov eax, dword ptr [esi + 4]
// 005fceba  57                   push edi
// 005fcebb  52                   push edx
// 005fcebc  ffd0                 call eax
// 005fcebe  83c410               add esp, 0x10
// 005fcec1  894610               mov dword ptr [esi + 0x10], eax
// 005fcec4  5f                   pop edi
// 005fcec5  59                   pop ecx
// 005fcec6  c3                   ret 
// 005fcec7  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fcecb  c744240400000000     mov dword ptr [esp + 4], 0
// 005fced3  7519                 jne 0x5fceee
// 005fced5  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fced8  8b06                 mov eax, dword ptr [esi]
// 005fceda  51                   push ecx
// 005fcedb  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fcede  6a04                 push 4
// 005fcee0  8d54240c             lea edx, [esp + 0xc]
// 005fcee4  52                   push edx
// 005fcee5  50                   push eax
// 005fcee6  ffd1                 call ecx
// 005fcee8  894610               mov dword ptr [esi + 0x10], eax
// 005fceeb  83c410               add esp, 0x10
// 005fceee  5f                   pop edi
// 005fceef  59                   pop ecx
// 005fcef0  c3                   ret 
// library lua-5.1.1/ldump.c (function _DumpString)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldump.c
