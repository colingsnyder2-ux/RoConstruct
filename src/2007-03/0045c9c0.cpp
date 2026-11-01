// from server: 100% by auto
// roc 2007-03 0045c9c0  unit: seg_00450000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045c9c0
//
// 0045c9c0  56                   push esi
// 0045c9c1  57                   push edi
// 0045c9c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0045c9c6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0045c9c9  f7d0                 not eax
// 0045c9cb  a801                 test al, 1
// 0045c9cd  8bf1                 mov esi, ecx
// 0045c9cf  741e                 je 0x45c9ef
// 0045c9d1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0045c9d4  51                   push ecx
// 0045c9d5  8bcf                 mov ecx, edi
// 0045c9d7  e83a241c00           call 0x61ee16
// 0045c9dc  8b5608               mov edx, dword ptr [esi + 8]
// 0045c9df  8b4604               mov eax, dword ptr [esi + 4]
// 0045c9e2  52                   push edx
// 0045c9e3  50                   push eax
// 0045c9e4  57                   push edi
// 0045c9e5  e8d6fa1c00           call 0x62c4c0
// 0045c9ea  5f                   pop edi
// 0045c9eb  5e                   pop esi
// 0045c9ec  c20400               ret 4
// 0045c9ef  8bcf                 mov ecx, edi
// 0045c9f1  e81a241c00           call 0x61ee10
// 0045c9f6  6aff                 push -1
// 0045c9f8  50                   push eax
// 0045c9f9  8bce                 mov ecx, esi
// 0045c9fb  e820e8ffff           call 0x45b220
// 0045ca00  8b5608               mov edx, dword ptr [esi + 8]
// 0045ca03  8b4604               mov eax, dword ptr [esi + 4]
// 0045ca06  52                   push edx
// 0045ca07  50                   push eax
// 0045ca08  57                   push edi
// 0045ca09  e8b2fa1c00           call 0x62c4c0
// 0045ca0e  5f                   pop edi
// 0045ca0f  5e                   pop esi
// 0045ca10  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
