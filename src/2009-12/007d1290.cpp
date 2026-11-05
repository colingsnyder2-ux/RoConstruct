// from server: 100% by auto
// roc 2009-12 007d1290  unit: seg_007d0000  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1290
//
// 007d1290  51                   push ecx
// 007d1291  57                   push edi
// 007d1292  85c0                 test eax, eax
// 007d1294  744f                 je 0x7d12e5
// 007d1296  8d7810               lea edi, [eax + 0x10]
// 007d1299  85ff                 test edi, edi
// 007d129b  7448                 je 0x7d12e5
// 007d129d  8b400c               mov eax, dword ptr [eax + 0xc]
// 007d12a0  40                   inc eax
// 007d12a1  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d12a5  89442404             mov dword ptr [esp + 4], eax
// 007d12a9  7561                 jne 0x7d130c
// 007d12ab  8b4608               mov eax, dword ptr [esi + 8]
// 007d12ae  8b16                 mov edx, dword ptr [esi]
// 007d12b0  50                   push eax
// 007d12b1  8b4604               mov eax, dword ptr [esi + 4]
// 007d12b4  6a04                 push 4
// 007d12b6  8d4c240c             lea ecx, [esp + 0xc]
// 007d12ba  51                   push ecx
// 007d12bb  52                   push edx
// 007d12bc  ffd0                 call eax
// 007d12be  894610               mov dword ptr [esi + 0x10], eax
// 007d12c1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d12c5  83c410               add esp, 0x10
// 007d12c8  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d12cc  753e                 jne 0x7d130c
// 007d12ce  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d12d1  8b16                 mov edx, dword ptr [esi]
// 007d12d3  51                   push ecx
// 007d12d4  50                   push eax
// 007d12d5  8b4604               mov eax, dword ptr [esi + 4]
// 007d12d8  57                   push edi
// 007d12d9  52                   push edx
// 007d12da  ffd0                 call eax
// 007d12dc  83c410               add esp, 0x10
// 007d12df  894610               mov dword ptr [esi + 0x10], eax
// 007d12e2  5f                   pop edi
// 007d12e3  59                   pop ecx
// 007d12e4  c3                   ret 
// 007d12e5  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d12e9  c744240400000000     mov dword ptr [esp + 4], 0
// 007d12f1  7519                 jne 0x7d130c
// 007d12f3  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d12f6  8b06                 mov eax, dword ptr [esi]
// 007d12f8  51                   push ecx
// 007d12f9  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d12fc  6a04                 push 4
// 007d12fe  8d54240c             lea edx, [esp + 0xc]
// 007d1302  52                   push edx
// 007d1303  50                   push eax
// 007d1304  ffd1                 call ecx
// 007d1306  894610               mov dword ptr [esi + 0x10], eax
// 007d1309  83c410               add esp, 0x10
// 007d130c  5f                   pop edi
// 007d130d  59                   pop ecx
// 007d130e  c3                   ret 
// library lua-5.1/ldump.c (function _DumpString)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldump.c
