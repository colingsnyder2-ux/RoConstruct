// from server: 100% by auto
// roc 2007-03 006975f0  unit: seg_00690000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006975f0
//
// 006975f0  56                   push esi
// 006975f1  57                   push edi
// 006975f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006975f6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006975f9  f7d0                 not eax
// 006975fb  a801                 test al, 1
// 006975fd  8bf1                 mov esi, ecx
// 006975ff  741e                 je 0x69761f
// 00697601  8b4e08               mov ecx, dword ptr [esi + 8]
// 00697604  51                   push ecx
// 00697605  8bcf                 mov ecx, edi
// 00697607  e80a78f8ff           call 0x61ee16
// 0069760c  8b5608               mov edx, dword ptr [esi + 8]
// 0069760f  8b4604               mov eax, dword ptr [esi + 4]
// 00697612  52                   push edx
// 00697613  50                   push eax
// 00697614  57                   push edi
// 00697615  e876fbffff           call 0x697190
// 0069761a  5f                   pop edi
// 0069761b  5e                   pop esi
// 0069761c  c20400               ret 4
// 0069761f  8bcf                 mov ecx, edi
// 00697621  e8ea77f8ff           call 0x61ee10
// 00697626  6aff                 push -1
// 00697628  50                   push eax
// 00697629  8bce                 mov ecx, esi
// 0069762b  e890f2ffff           call 0x6968c0
// 00697630  8b5608               mov edx, dword ptr [esi + 8]
// 00697633  8b4604               mov eax, dword ptr [esi + 4]
// 00697636  52                   push edx
// 00697637  50                   push eax
// 00697638  57                   push edi
// 00697639  e852fbffff           call 0x697190
// 0069763e  5f                   pop edi
// 0069763f  5e                   pop esi
// 00697640  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
