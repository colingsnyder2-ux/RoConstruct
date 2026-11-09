// from server: 100% by auto
// roc 2010-06 0081e2e0  unit: CXTPPropertyGridView::UWNDRECT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081e2e0
//
// 0081e2e0  56                   push esi
// 0081e2e1  57                   push edi
// 0081e2e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0081e2e6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0081e2e9  f7d0                 not eax
// 0081e2eb  8bf1                 mov esi, ecx
// 0081e2ed  a801                 test al, 1
// 0081e2ef  741e                 je 0x81e30f
// 0081e2f1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0081e2f4  51                   push ecx
// 0081e2f5  8bcf                 mov ecx, edi
// 0081e2f7  e838a2f8ff           call 0x7a8534
// 0081e2fc  8b5608               mov edx, dword ptr [esi + 8]
// 0081e2ff  8b4604               mov eax, dword ptr [esi + 4]
// 0081e302  52                   push edx
// 0081e303  50                   push eax
// 0081e304  57                   push edi
// 0081e305  e836fbffff           call 0x81de40
// 0081e30a  5f                   pop edi
// 0081e30b  5e                   pop esi
// 0081e30c  c20400               ret 4
// 0081e30f  8bcf                 mov ecx, edi
// 0081e311  e818a2f8ff           call 0x7a852e
// 0081e316  6aff                 push -1
// 0081e318  50                   push eax
// 0081e319  8bce                 mov ecx, esi
// 0081e31b  e820d7ffff           call 0x81ba40
// 0081e320  8b5608               mov edx, dword ptr [esi + 8]
// 0081e323  8b4604               mov eax, dword ptr [esi + 4]
// 0081e326  52                   push edx
// 0081e327  50                   push eax
// 0081e328  57                   push edi
// 0081e329  e812fbffff           call 0x81de40
// 0081e32e  5f                   pop edi
// 0081e32f  5e                   pop esi
// 0081e330  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
