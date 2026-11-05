// from server: 100% by auto
// roc 2011-06 00884510  unit: CXTPControlGallery::UGALLERYITEM_POSITION::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00884510
//
// 00884510  56                   push esi
// 00884511  57                   push edi
// 00884512  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00884516  8b4718               mov eax, dword ptr [edi + 0x18]
// 00884519  f7d0                 not eax
// 0088451b  8bf1                 mov esi, ecx
// 0088451d  a801                 test al, 1
// 0088451f  741e                 je 0x88453f
// 00884521  8b4e08               mov ecx, dword ptr [esi + 8]
// 00884524  51                   push ecx
// 00884525  8bcf                 mov ecx, edi
// 00884527  e8cc66f8ff           call 0x80abf8
// 0088452c  8b5608               mov edx, dword ptr [esi + 8]
// 0088452f  8b4604               mov eax, dword ptr [esi + 4]
// 00884532  52                   push edx
// 00884533  50                   push eax
// 00884534  57                   push edi
// 00884535  e896dbffff           call 0x8820d0
// 0088453a  5f                   pop edi
// 0088453b  5e                   pop esi
// 0088453c  c20400               ret 4
// 0088453f  8bcf                 mov ecx, edi
// 00884541  e8ac66f8ff           call 0x80abf2
// 00884546  6aff                 push -1
// 00884548  50                   push eax
// 00884549  8bce                 mov ecx, esi
// 0088454b  e8d0d9ffff           call 0x881f20
// 00884550  8b5608               mov edx, dword ptr [esi + 8]
// 00884553  8b4604               mov eax, dword ptr [esi + 4]
// 00884556  52                   push edx
// 00884557  50                   push eax
// 00884558  57                   push edi
// 00884559  e872dbffff           call 0x8820d0
// 0088455e  5f                   pop edi
// 0088455f  5e                   pop esi
// 00884560  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
