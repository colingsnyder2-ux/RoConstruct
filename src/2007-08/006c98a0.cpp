// from server: 100% by auto
// roc 2007-08 006c98a0  unit: VCRect::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006c98a0
//
// 006c98a0  56                   push esi
// 006c98a1  57                   push edi
// 006c98a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006c98a6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006c98a9  f7d0                 not eax
// 006c98ab  a801                 test al, 1
// 006c98ad  8bf1                 mov esi, ecx
// 006c98af  741e                 je 0x6c98cf
// 006c98b1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006c98b4  51                   push ecx
// 006c98b5  8bcf                 mov ecx, edi
// 006c98b7  e8f06df6ff           call 0x6306ac
// 006c98bc  8b5608               mov edx, dword ptr [esi + 8]
// 006c98bf  8b4604               mov eax, dword ptr [esi + 4]
// 006c98c2  52                   push edx
// 006c98c3  50                   push eax
// 006c98c4  57                   push edi
// 006c98c5  e81609fcff           call 0x68a1e0
// 006c98ca  5f                   pop edi
// 006c98cb  5e                   pop esi
// 006c98cc  c20400               ret 4
// 006c98cf  8bcf                 mov ecx, edi
// 006c98d1  e8d06df6ff           call 0x6306a6
// 006c98d6  6aff                 push -1
// 006c98d8  50                   push eax
// 006c98d9  8bce                 mov ecx, esi
// 006c98db  e870f3ffff           call 0x6c8c50
// 006c98e0  8b5608               mov edx, dword ptr [esi + 8]
// 006c98e3  8b4604               mov eax, dword ptr [esi + 4]
// 006c98e6  52                   push edx
// 006c98e7  50                   push eax
// 006c98e8  57                   push edi
// 006c98e9  e8f208fcff           call 0x68a1e0
// 006c98ee  5f                   pop edi
// 006c98ef  5e                   pop esi
// 006c98f0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
