// from server: 100% by auto
// roc 2009-12 0086a2e0  unit: CXTPPropertyGridView::UWNDRECT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086a2e0
//
// 0086a2e0  56                   push esi
// 0086a2e1  57                   push edi
// 0086a2e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0086a2e6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0086a2e9  f7d0                 not eax
// 0086a2eb  8bf1                 mov esi, ecx
// 0086a2ed  a801                 test al, 1
// 0086a2ef  741e                 je 0x86a30f
// 0086a2f1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0086a2f4  51                   push ecx
// 0086a2f5  8bcf                 mov ecx, edi
// 0086a2f7  e8f8a0f8ff           call 0x7f43f4
// 0086a2fc  8b5608               mov edx, dword ptr [esi + 8]
// 0086a2ff  8b4604               mov eax, dword ptr [esi + 4]
// 0086a302  52                   push edx
// 0086a303  50                   push eax
// 0086a304  57                   push edi
// 0086a305  e836fbffff           call 0x869e40
// 0086a30a  5f                   pop edi
// 0086a30b  5e                   pop esi
// 0086a30c  c20400               ret 4
// 0086a30f  8bcf                 mov ecx, edi
// 0086a311  e8d8a0f8ff           call 0x7f43ee
// 0086a316  6aff                 push -1
// 0086a318  50                   push eax
// 0086a319  8bce                 mov ecx, esi
// 0086a31b  e810d7ffff           call 0x867a30
// 0086a320  8b5608               mov edx, dword ptr [esi + 8]
// 0086a323  8b4604               mov eax, dword ptr [esi + 4]
// 0086a326  52                   push edx
// 0086a327  50                   push eax
// 0086a328  57                   push edi
// 0086a329  e812fbffff           call 0x869e40
// 0086a32e  5f                   pop edi
// 0086a32f  5e                   pop esi
// 0086a330  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
