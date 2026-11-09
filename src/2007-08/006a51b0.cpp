// from server: 100% by auto
// roc 2007-08 006a51b0  unit: UtagACCEL::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a51b0
//
// 006a51b0  56                   push esi
// 006a51b1  57                   push edi
// 006a51b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006a51b6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006a51b9  f7d0                 not eax
// 006a51bb  a801                 test al, 1
// 006a51bd  8bf1                 mov esi, ecx
// 006a51bf  741e                 je 0x6a51df
// 006a51c1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006a51c4  51                   push ecx
// 006a51c5  8bcf                 mov ecx, edi
// 006a51c7  e8e0b4f8ff           call 0x6306ac
// 006a51cc  8b5608               mov edx, dword ptr [esi + 8]
// 006a51cf  8b4604               mov eax, dword ptr [esi + 4]
// 006a51d2  52                   push edx
// 006a51d3  50                   push eax
// 006a51d4  57                   push edi
// 006a51d5  e876fbffff           call 0x6a4d50
// 006a51da  5f                   pop edi
// 006a51db  5e                   pop esi
// 006a51dc  c20400               ret 4
// 006a51df  8bcf                 mov ecx, edi
// 006a51e1  e8c0b4f8ff           call 0x6306a6
// 006a51e6  6aff                 push -1
// 006a51e8  50                   push eax
// 006a51e9  8bce                 mov ecx, esi
// 006a51eb  e8f0f2ffff           call 0x6a44e0
// 006a51f0  8b5608               mov edx, dword ptr [esi + 8]
// 006a51f3  8b4604               mov eax, dword ptr [esi + 4]
// 006a51f6  52                   push edx
// 006a51f7  50                   push eax
// 006a51f8  57                   push edi
// 006a51f9  e852fbffff           call 0x6a4d50
// 006a51fe  5f                   pop edi
// 006a51ff  5e                   pop esi
// 006a5200  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
