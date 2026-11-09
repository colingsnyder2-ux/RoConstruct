// from server: 100% by auto
// roc 2009-06 0079f2f0  unit: CXTPControlGallery::UGALLERYITEM_POSITION::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079f2f0
//
// 0079f2f0  56                   push esi
// 0079f2f1  57                   push edi
// 0079f2f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0079f2f6  8b4718               mov eax, dword ptr [edi + 0x18]
// 0079f2f9  f7d0                 not eax
// 0079f2fb  8bf1                 mov esi, ecx
// 0079f2fd  a801                 test al, 1
// 0079f2ff  741e                 je 0x79f31f
// 0079f301  8b4e08               mov ecx, dword ptr [esi + 8]
// 0079f304  51                   push ecx
// 0079f305  8bcf                 mov ecx, edi
// 0079f307  e8baa2f7ff           call 0x7195c6
// 0079f30c  8b5608               mov edx, dword ptr [esi + 8]
// 0079f30f  8b4604               mov eax, dword ptr [esi + 4]
// 0079f312  52                   push edx
// 0079f313  50                   push eax
// 0079f314  57                   push edi
// 0079f315  e896dbffff           call 0x79ceb0
// 0079f31a  5f                   pop edi
// 0079f31b  5e                   pop esi
// 0079f31c  c20400               ret 4
// 0079f31f  8bcf                 mov ecx, edi
// 0079f321  e89aa2f7ff           call 0x7195c0
// 0079f326  6aff                 push -1
// 0079f328  50                   push eax
// 0079f329  8bce                 mov ecx, esi
// 0079f32b  e8d0d9ffff           call 0x79cd00
// 0079f330  8b5608               mov edx, dword ptr [esi + 8]
// 0079f333  8b4604               mov eax, dword ptr [esi + 4]
// 0079f336  52                   push edx
// 0079f337  50                   push eax
// 0079f338  57                   push edi
// 0079f339  e872dbffff           call 0x79ceb0
// 0079f33e  5f                   pop edi
// 0079f33f  5e                   pop esi
// 0079f340  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
