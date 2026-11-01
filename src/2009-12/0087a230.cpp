// from server: 100% by auto
// roc 2009-12 0087a230  unit: CXTPControlGallery::UGALLERYITEM_POSITION::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087a230
//
// 0087a230  56                   push esi
// 0087a231  57                   push edi
// 0087a232  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0087a236  8b4718               mov eax, dword ptr [edi + 0x18]
// 0087a239  f7d0                 not eax
// 0087a23b  8bf1                 mov esi, ecx
// 0087a23d  a801                 test al, 1
// 0087a23f  741e                 je 0x87a25f
// 0087a241  8b4e08               mov ecx, dword ptr [esi + 8]
// 0087a244  51                   push ecx
// 0087a245  8bcf                 mov ecx, edi
// 0087a247  e8a8a1f7ff           call 0x7f43f4
// 0087a24c  8b5608               mov edx, dword ptr [esi + 8]
// 0087a24f  8b4604               mov eax, dword ptr [esi + 4]
// 0087a252  52                   push edx
// 0087a253  50                   push eax
// 0087a254  57                   push edi
// 0087a255  e8e6dbffff           call 0x877e40
// 0087a25a  5f                   pop edi
// 0087a25b  5e                   pop esi
// 0087a25c  c20400               ret 4
// 0087a25f  8bcf                 mov ecx, edi
// 0087a261  e888a1f7ff           call 0x7f43ee
// 0087a266  6aff                 push -1
// 0087a268  50                   push eax
// 0087a269  8bce                 mov ecx, esi
// 0087a26b  e820daffff           call 0x877c90
// 0087a270  8b5608               mov edx, dword ptr [esi + 8]
// 0087a273  8b4604               mov eax, dword ptr [esi + 4]
// 0087a276  52                   push edx
// 0087a277  50                   push eax
// 0087a278  57                   push edi
// 0087a279  e8c2dbffff           call 0x877e40
// 0087a27e  5f                   pop edi
// 0087a27f  5e                   pop esi
// 0087a280  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
