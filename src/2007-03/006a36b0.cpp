// from server: 100% by auto
// roc 2007-03 006a36b0  unit: seg_006a0000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006a36b0
//
// 006a36b0  56                   push esi
// 006a36b1  57                   push edi
// 006a36b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006a36b6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006a36b9  f7d0                 not eax
// 006a36bb  a801                 test al, 1
// 006a36bd  8bf1                 mov esi, ecx
// 006a36bf  741e                 je 0x6a36df
// 006a36c1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006a36c4  51                   push ecx
// 006a36c5  8bcf                 mov ecx, edi
// 006a36c7  e84ab7f7ff           call 0x61ee16
// 006a36cc  8b5608               mov edx, dword ptr [esi + 8]
// 006a36cf  8b4604               mov eax, dword ptr [esi + 4]
// 006a36d2  52                   push edx
// 006a36d3  50                   push eax
// 006a36d4  57                   push edi
// 006a36d5  e856e3ffff           call 0x6a1a30
// 006a36da  5f                   pop edi
// 006a36db  5e                   pop esi
// 006a36dc  c20400               ret 4
// 006a36df  8bcf                 mov ecx, edi
// 006a36e1  e82ab7f7ff           call 0x61ee10
// 006a36e6  6aff                 push -1
// 006a36e8  50                   push eax
// 006a36e9  8bce                 mov ecx, esi
// 006a36eb  e870c6ffff           call 0x69fd60
// 006a36f0  8b5608               mov edx, dword ptr [esi + 8]
// 006a36f3  8b4604               mov eax, dword ptr [esi + 4]
// 006a36f6  52                   push edx
// 006a36f7  50                   push eax
// 006a36f8  57                   push edi
// 006a36f9  e832e3ffff           call 0x6a1a30
// 006a36fe  5f                   pop edi
// 006a36ff  5e                   pop esi
// 006a3700  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
