// from server: 100% by auto
// roc 2007-08 006b7c00  unit: CXTPControlGallery::UGALLERYITEM_POSITION::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b7c00
//
// 006b7c00  56                   push esi
// 006b7c01  57                   push edi
// 006b7c02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b7c06  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b7c09  f7d0                 not eax
// 006b7c0b  a801                 test al, 1
// 006b7c0d  8bf1                 mov esi, ecx
// 006b7c0f  741e                 je 0x6b7c2f
// 006b7c11  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b7c14  51                   push ecx
// 006b7c15  8bcf                 mov ecx, edi
// 006b7c17  e8908af7ff           call 0x6306ac
// 006b7c1c  8b5608               mov edx, dword ptr [esi + 8]
// 006b7c1f  8b4604               mov eax, dword ptr [esi + 4]
// 006b7c22  52                   push edx
// 006b7c23  50                   push eax
// 006b7c24  57                   push edi
// 006b7c25  e846e2ffff           call 0x6b5e70
// 006b7c2a  5f                   pop edi
// 006b7c2b  5e                   pop esi
// 006b7c2c  c20400               ret 4
// 006b7c2f  8bcf                 mov ecx, edi
// 006b7c31  e8708af7ff           call 0x6306a6
// 006b7c36  6aff                 push -1
// 006b7c38  50                   push eax
// 006b7c39  8bce                 mov ecx, esi
// 006b7c3b  e870bfffff           call 0x6b3bb0
// 006b7c40  8b5608               mov edx, dword ptr [esi + 8]
// 006b7c43  8b4604               mov eax, dword ptr [esi + 4]
// 006b7c46  52                   push edx
// 006b7c47  50                   push eax
// 006b7c48  57                   push edi
// 006b7c49  e822e2ffff           call 0x6b5e70
// 006b7c4e  5f                   pop edi
// 006b7c4f  5e                   pop esi
// 006b7c50  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
