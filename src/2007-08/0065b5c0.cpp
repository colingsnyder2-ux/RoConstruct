// from server: 100% by auto
// roc 2007-08 0065b5c0  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0065b5c0
//
// 0065b5c0  56                   push esi
// 0065b5c1  57                   push edi
// 0065b5c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0065b5c6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0065b5c9  f7d0                 not eax
// 0065b5cb  a801                 test al, 1
// 0065b5cd  8bf1                 mov esi, ecx
// 0065b5cf  741e                 je 0x65b5ef
// 0065b5d1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0065b5d4  51                   push ecx
// 0065b5d5  8bcf                 mov ecx, edi
// 0065b5d7  e8d050fdff           call 0x6306ac
// 0065b5dc  8b5608               mov edx, dword ptr [esi + 8]
// 0065b5df  8b4604               mov eax, dword ptr [esi + 4]
// 0065b5e2  52                   push edx
// 0065b5e3  50                   push eax
// 0065b5e4  57                   push edi
// 0065b5e5  e8a6110800           call 0x6dc790
// 0065b5ea  5f                   pop edi
// 0065b5eb  5e                   pop esi
// 0065b5ec  c20400               ret 4
// 0065b5ef  8bcf                 mov ecx, edi
// 0065b5f1  e8b050fdff           call 0x6306a6
// 0065b5f6  6aff                 push -1
// 0065b5f8  50                   push eax
// 0065b5f9  8bce                 mov ecx, esi
// 0065b5fb  e880edffff           call 0x65a380
// 0065b600  8b5608               mov edx, dword ptr [esi + 8]
// 0065b603  8b4604               mov eax, dword ptr [esi + 4]
// 0065b606  52                   push edx
// 0065b607  50                   push eax
// 0065b608  57                   push edi
// 0065b609  e882110800           call 0x6dc790
// 0065b60e  5f                   pop edi
// 0065b60f  5e                   pop esi
// 0065b610  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
