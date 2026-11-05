// from server: 100% by auto
// roc 2008-06 00716b20  unit: CXTPPropertyGridView::UWNDRECT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00716b20
//
// 00716b20  56                   push esi
// 00716b21  57                   push edi
// 00716b22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00716b26  8b4718               mov eax, dword ptr [edi + 0x18]
// 00716b29  f7d0                 not eax
// 00716b2b  8bf1                 mov esi, ecx
// 00716b2d  a801                 test al, 1
// 00716b2f  741e                 je 0x716b4f
// 00716b31  8b4e08               mov ecx, dword ptr [esi + 8]
// 00716b34  51                   push ecx
// 00716b35  8bcf                 mov ecx, edi
// 00716b37  e80ca6f8ff           call 0x6a1148
// 00716b3c  8b5608               mov edx, dword ptr [esi + 8]
// 00716b3f  8b4604               mov eax, dword ptr [esi + 4]
// 00716b42  52                   push edx
// 00716b43  50                   push eax
// 00716b44  57                   push edi
// 00716b45  e836fbffff           call 0x716680
// 00716b4a  5f                   pop edi
// 00716b4b  5e                   pop esi
// 00716b4c  c20400               ret 4
// 00716b4f  8bcf                 mov ecx, edi
// 00716b51  e8eca5f8ff           call 0x6a1142
// 00716b56  6aff                 push -1
// 00716b58  50                   push eax
// 00716b59  8bce                 mov ecx, esi
// 00716b5b  e820d7ffff           call 0x714280
// 00716b60  8b5608               mov edx, dword ptr [esi + 8]
// 00716b63  8b4604               mov eax, dword ptr [esi + 4]
// 00716b66  52                   push edx
// 00716b67  50                   push eax
// 00716b68  57                   push edi
// 00716b69  e812fbffff           call 0x716680
// 00716b6e  5f                   pop edi
// 00716b6f  5e                   pop esi
// 00716b70  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
