// from server: 100% by auto
// roc 2007-08 00702690  unit: HH::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00702690
//
// 00702690  56                   push esi
// 00702691  57                   push edi
// 00702692  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00702696  8b4718               mov eax, dword ptr [edi + 0x18]
// 00702699  f7d0                 not eax
// 0070269b  a801                 test al, 1
// 0070269d  8bf1                 mov esi, ecx
// 0070269f  741e                 je 0x7026bf
// 007026a1  8b4e08               mov ecx, dword ptr [esi + 8]
// 007026a4  51                   push ecx
// 007026a5  8bcf                 mov ecx, edi
// 007026a7  e800e0f2ff           call 0x6306ac
// 007026ac  8b5608               mov edx, dword ptr [esi + 8]
// 007026af  8b4604               mov eax, dword ptr [esi + 4]
// 007026b2  52                   push edx
// 007026b3  50                   push eax
// 007026b4  57                   push edi
// 007026b5  e8a691f8ff           call 0x68b860
// 007026ba  5f                   pop edi
// 007026bb  5e                   pop esi
// 007026bc  c20400               ret 4
// 007026bf  8bcf                 mov ecx, edi
// 007026c1  e8e0dff2ff           call 0x6306a6
// 007026c6  6aff                 push -1
// 007026c8  50                   push eax
// 007026c9  8bce                 mov ecx, esi
// 007026cb  e8e0d3ffff           call 0x6ffab0
// 007026d0  8b5608               mov edx, dword ptr [esi + 8]
// 007026d3  8b4604               mov eax, dword ptr [esi + 4]
// 007026d6  52                   push edx
// 007026d7  50                   push eax
// 007026d8  57                   push edi
// 007026d9  e88291f8ff           call 0x68b860
// 007026de  5f                   pop edi
// 007026df  5e                   pop esi
// 007026e0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
