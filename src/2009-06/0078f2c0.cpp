// from server: 100% by auto
// roc 2009-06 0078f2c0  unit: CXTPPropertyGridView::UWNDRECT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078f2c0
//
// 0078f2c0  56                   push esi
// 0078f2c1  57                   push edi
// 0078f2c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0078f2c6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0078f2c9  f7d0                 not eax
// 0078f2cb  8bf1                 mov esi, ecx
// 0078f2cd  a801                 test al, 1
// 0078f2cf  741e                 je 0x78f2ef
// 0078f2d1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078f2d4  51                   push ecx
// 0078f2d5  8bcf                 mov ecx, edi
// 0078f2d7  e8eaa2f8ff           call 0x7195c6
// 0078f2dc  8b5608               mov edx, dword ptr [esi + 8]
// 0078f2df  8b4604               mov eax, dword ptr [esi + 4]
// 0078f2e2  52                   push edx
// 0078f2e3  50                   push eax
// 0078f2e4  57                   push edi
// 0078f2e5  e836fbffff           call 0x78ee20
// 0078f2ea  5f                   pop edi
// 0078f2eb  5e                   pop esi
// 0078f2ec  c20400               ret 4
// 0078f2ef  8bcf                 mov ecx, edi
// 0078f2f1  e8caa2f8ff           call 0x7195c0
// 0078f2f6  6aff                 push -1
// 0078f2f8  50                   push eax
// 0078f2f9  8bce                 mov ecx, esi
// 0078f2fb  e820d7ffff           call 0x78ca20
// 0078f300  8b5608               mov edx, dword ptr [esi + 8]
// 0078f303  8b4604               mov eax, dword ptr [esi + 4]
// 0078f306  52                   push edx
// 0078f307  50                   push eax
// 0078f308  57                   push edi
// 0078f309  e812fbffff           call 0x78ee20
// 0078f30e  5f                   pop edi
// 0078f30f  5e                   pop esi
// 0078f310  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
