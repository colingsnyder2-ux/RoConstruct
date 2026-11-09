// from server: 100% by auto
// roc 2010-06 00827480  unit: CXTPControlGallery::UGALLERYITEM_POSITION::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00827480
//
// 00827480  56                   push esi
// 00827481  57                   push edi
// 00827482  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00827486  8b4718               mov eax, dword ptr [edi + 0x18]
// 00827489  f7d0                 not eax
// 0082748b  8bf1                 mov esi, ecx
// 0082748d  a801                 test al, 1
// 0082748f  741e                 je 0x8274af
// 00827491  8b4e08               mov ecx, dword ptr [esi + 8]
// 00827494  51                   push ecx
// 00827495  8bcf                 mov ecx, edi
// 00827497  e89810f8ff           call 0x7a8534
// 0082749c  8b5608               mov edx, dword ptr [esi + 8]
// 0082749f  8b4604               mov eax, dword ptr [esi + 4]
// 008274a2  52                   push edx
// 008274a3  50                   push eax
// 008274a4  57                   push edi
// 008274a5  e896dbffff           call 0x825040
// 008274aa  5f                   pop edi
// 008274ab  5e                   pop esi
// 008274ac  c20400               ret 4
// 008274af  8bcf                 mov ecx, edi
// 008274b1  e87810f8ff           call 0x7a852e
// 008274b6  6aff                 push -1
// 008274b8  50                   push eax
// 008274b9  8bce                 mov ecx, esi
// 008274bb  e8d0d9ffff           call 0x824e90
// 008274c0  8b5608               mov edx, dword ptr [esi + 8]
// 008274c3  8b4604               mov eax, dword ptr [esi + 4]
// 008274c6  52                   push edx
// 008274c7  50                   push eax
// 008274c8  57                   push edi
// 008274c9  e872dbffff           call 0x825040
// 008274ce  5f                   pop edi
// 008274cf  5e                   pop esi
// 008274d0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
