// from server: 100% by auto
// roc 2009-06 0077bcd0  unit: VCRect::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077bcd0
//
// 0077bcd0  56                   push esi
// 0077bcd1  57                   push edi
// 0077bcd2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077bcd6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0077bcd9  f7d0                 not eax
// 0077bcdb  8bf1                 mov esi, ecx
// 0077bcdd  a801                 test al, 1
// 0077bcdf  741e                 je 0x77bcff
// 0077bce1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0077bce4  51                   push ecx
// 0077bce5  8bcf                 mov ecx, edi
// 0077bce7  e8dad8f9ff           call 0x7195c6
// 0077bcec  8b5608               mov edx, dword ptr [esi + 8]
// 0077bcef  8b4604               mov eax, dword ptr [esi + 4]
// 0077bcf2  52                   push edx
// 0077bcf3  50                   push eax
// 0077bcf4  57                   push edi
// 0077bcf5  e816e9ffff           call 0x77a610
// 0077bcfa  5f                   pop edi
// 0077bcfb  5e                   pop esi
// 0077bcfc  c20400               ret 4
// 0077bcff  8bcf                 mov ecx, edi
// 0077bd01  e8bad8f9ff           call 0x7195c0
// 0077bd06  6aff                 push -1
// 0077bd08  50                   push eax
// 0077bd09  8bce                 mov ecx, esi
// 0077bd0b  e830150400           call 0x7bd240
// 0077bd10  8b5608               mov edx, dword ptr [esi + 8]
// 0077bd13  8b4604               mov eax, dword ptr [esi + 4]
// 0077bd16  52                   push edx
// 0077bd17  50                   push eax
// 0077bd18  57                   push edi
// 0077bd19  e8f2e8ffff           call 0x77a610
// 0077bd1e  5f                   pop edi
// 0077bd1f  5e                   pop esi
// 0077bd20  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
