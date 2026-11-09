// from server: 100% by auto
// roc 2009-06 00735900  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00735900
//
// 00735900  56                   push esi
// 00735901  8bf1                 mov esi, ecx
// 00735903  837e1000             cmp dword ptr [esi + 0x10], 0
// 00735907  7538                 jne 0x735941
// 00735909  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073590c  6a10                 push 0x10
// 0073590e  50                   push eax
// 0073590f  8d4e14               lea ecx, [esi + 0x14]
// 00735912  51                   push ecx
// 00735913  e8a23cfeff           call 0x7195ba
// 00735918  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0073591b  8bd1                 mov edx, ecx
// 0073591d  83c004               add eax, 4
// 00735920  c1e204               shl edx, 4
// 00735923  83c1ff               add ecx, -1
// 00735926  8d4410f0             lea eax, [eax + edx - 0x10]
// 0073592a  7815                 js 0x735941
// 0073592c  8d642400             lea esp, [esp]
// 00735930  8b5610               mov edx, dword ptr [esi + 0x10]
// 00735933  895008               mov dword ptr [eax + 8], edx
// 00735936  894610               mov dword ptr [esi + 0x10], eax
// 00735939  49                   dec ecx
// 0073593a  83e810               sub eax, 0x10
// 0073593d  85c9                 test ecx, ecx
// 0073593f  7def                 jge 0x735930
// 00735941  8b4610               mov eax, dword ptr [esi + 0x10]
// 00735944  85c0                 test eax, eax
// 00735946  7505                 jne 0x73594d
// 00735948  e89733feff           call 0x718ce4
// 0073594d  8b5008               mov edx, dword ptr [eax + 8]
// 00735950  33c9                 xor ecx, ecx
// 00735952  8908                 mov dword ptr [eax], ecx
// 00735954  894804               mov dword ptr [eax + 4], ecx
// 00735957  89480c               mov dword ptr [eax + 0xc], ecx
// 0073595a  895008               mov dword ptr [eax + 8], edx
// 0073595d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00735960  8b5108               mov edx, dword ptr [ecx + 8]
// 00735963  ff460c               inc dword ptr [esi + 0xc]
// 00735966  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0073596a  895610               mov dword ptr [esi + 0x10], edx
// 0073596d  8908                 mov dword ptr [eax], ecx
// 0073596f  5e                   pop esi
// 00735970  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?NewAssoc@?$CMap@PAUHICON__@@PAU1@HH@@IAEPAVCAssoc@1@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
