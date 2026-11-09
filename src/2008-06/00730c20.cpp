// from server: 100% by auto
// roc 2008-06 00730c20  unit: CXTPControlGallery::UGALLERYITEM_POSITION::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00730c20
//
// 00730c20  56                   push esi
// 00730c21  57                   push edi
// 00730c22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00730c26  8b4718               mov eax, dword ptr [edi + 0x18]
// 00730c29  f7d0                 not eax
// 00730c2b  8bf1                 mov esi, ecx
// 00730c2d  a801                 test al, 1
// 00730c2f  741e                 je 0x730c4f
// 00730c31  8b4e08               mov ecx, dword ptr [esi + 8]
// 00730c34  51                   push ecx
// 00730c35  8bcf                 mov ecx, edi
// 00730c37  e80c05f7ff           call 0x6a1148
// 00730c3c  8b5608               mov edx, dword ptr [esi + 8]
// 00730c3f  8b4604               mov eax, dword ptr [esi + 4]
// 00730c42  52                   push edx
// 00730c43  50                   push eax
// 00730c44  57                   push edi
// 00730c45  e8e6dbffff           call 0x72e830
// 00730c4a  5f                   pop edi
// 00730c4b  5e                   pop esi
// 00730c4c  c20400               ret 4
// 00730c4f  8bcf                 mov ecx, edi
// 00730c51  e8ec04f7ff           call 0x6a1142
// 00730c56  6aff                 push -1
// 00730c58  50                   push eax
// 00730c59  8bce                 mov ecx, esi
// 00730c5b  e820daffff           call 0x72e680
// 00730c60  8b5608               mov edx, dword ptr [esi + 8]
// 00730c63  8b4604               mov eax, dword ptr [esi + 4]
// 00730c66  52                   push edx
// 00730c67  50                   push eax
// 00730c68  57                   push edi
// 00730c69  e8c2dbffff           call 0x72e830
// 00730c6e  5f                   pop edi
// 00730c6f  5e                   pop esi
// 00730c70  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
