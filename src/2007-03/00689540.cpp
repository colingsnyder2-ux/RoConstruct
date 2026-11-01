// from server: 100% by auto
// roc 2007-03 00689540  unit: seg_00680000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00689540
//
// 00689540  56                   push esi
// 00689541  57                   push edi
// 00689542  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00689546  8b4718               mov eax, dword ptr [edi + 0x18]
// 00689549  f7d0                 not eax
// 0068954b  a801                 test al, 1
// 0068954d  8bf1                 mov esi, ecx
// 0068954f  741e                 je 0x68956f
// 00689551  8b4e08               mov ecx, dword ptr [esi + 8]
// 00689554  51                   push ecx
// 00689555  8bcf                 mov ecx, edi
// 00689557  e8ba58f9ff           call 0x61ee16
// 0068955c  8b5608               mov edx, dword ptr [esi + 8]
// 0068955f  8b4604               mov eax, dword ptr [esi + 4]
// 00689562  52                   push edx
// 00689563  50                   push eax
// 00689564  57                   push edi
// 00689565  e896faffff           call 0x689000
// 0068956a  5f                   pop edi
// 0068956b  5e                   pop esi
// 0068956c  c20400               ret 4
// 0068956f  8bcf                 mov ecx, edi
// 00689571  e89a58f9ff           call 0x61ee10
// 00689576  6aff                 push -1
// 00689578  50                   push eax
// 00689579  8bce                 mov ecx, esi
// 0068957b  e8c0d9ffff           call 0x686f40
// 00689580  8b5608               mov edx, dword ptr [esi + 8]
// 00689583  8b4604               mov eax, dword ptr [esi + 4]
// 00689586  52                   push edx
// 00689587  50                   push eax
// 00689588  57                   push edi
// 00689589  e872faffff           call 0x689000
// 0068958e  5f                   pop edi
// 0068958f  5e                   pop esi
// 00689590  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
