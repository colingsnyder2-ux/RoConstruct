// from server: 100% by auto
// roc 2007-03 006952c0  unit: seg_00690000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006952c0
//
// 006952c0  56                   push esi
// 006952c1  57                   push edi
// 006952c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006952c6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006952c9  f7d0                 not eax
// 006952cb  a801                 test al, 1
// 006952cd  8bf1                 mov esi, ecx
// 006952cf  741e                 je 0x6952ef
// 006952d1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006952d4  51                   push ecx
// 006952d5  8bcf                 mov ecx, edi
// 006952d7  e83a9bf8ff           call 0x61ee16
// 006952dc  8b5608               mov edx, dword ptr [esi + 8]
// 006952df  8b4604               mov eax, dword ptr [esi + 4]
// 006952e2  52                   push edx
// 006952e3  50                   push eax
// 006952e4  57                   push edi
// 006952e5  e846fcffff           call 0x694f30
// 006952ea  5f                   pop edi
// 006952eb  5e                   pop esi
// 006952ec  c20400               ret 4
// 006952ef  8bcf                 mov ecx, edi
// 006952f1  e81a9bf8ff           call 0x61ee10
// 006952f6  6aff                 push -1
// 006952f8  50                   push eax
// 006952f9  8bce                 mov ecx, esi
// 006952fb  e860f9ffff           call 0x694c60
// 00695300  8b5608               mov edx, dword ptr [esi + 8]
// 00695303  8b4604               mov eax, dword ptr [esi + 4]
// 00695306  52                   push edx
// 00695307  50                   push eax
// 00695308  57                   push edi
// 00695309  e822fcffff           call 0x694f30
// 0069530e  5f                   pop edi
// 0069530f  5e                   pop esi
// 00695310  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
