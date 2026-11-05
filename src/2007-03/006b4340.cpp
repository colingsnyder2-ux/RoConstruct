// from server: 100% by auto
// roc 2007-03 006b4340  unit: seg_006b0000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b4340
//
// 006b4340  56                   push esi
// 006b4341  57                   push edi
// 006b4342  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b4346  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b4349  f7d0                 not eax
// 006b434b  a801                 test al, 1
// 006b434d  8bf1                 mov esi, ecx
// 006b434f  741e                 je 0x6b436f
// 006b4351  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b4354  51                   push ecx
// 006b4355  8bcf                 mov ecx, edi
// 006b4357  e8baaaf6ff           call 0x61ee16
// 006b435c  8b5608               mov edx, dword ptr [esi + 8]
// 006b435f  8b4604               mov eax, dword ptr [esi + 4]
// 006b4362  52                   push edx
// 006b4363  50                   push eax
// 006b4364  57                   push edi
// 006b4365  e866fdffff           call 0x6b40d0
// 006b436a  5f                   pop edi
// 006b436b  5e                   pop esi
// 006b436c  c20400               ret 4
// 006b436f  8bcf                 mov ecx, edi
// 006b4371  e89aaaf6ff           call 0x61ee10
// 006b4376  6aff                 push -1
// 006b4378  50                   push eax
// 006b4379  8bce                 mov ecx, esi
// 006b437b  e870a1fbff           call 0x66e4f0
// 006b4380  8b5608               mov edx, dword ptr [esi + 8]
// 006b4383  8b4604               mov eax, dword ptr [esi + 4]
// 006b4386  52                   push edx
// 006b4387  50                   push eax
// 006b4388  57                   push edi
// 006b4389  e842fdffff           call 0x6b40d0
// 006b438e  5f                   pop edi
// 006b438f  5e                   pop esi
// 006b4390  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
