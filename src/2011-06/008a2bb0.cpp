// from server: 100% by auto
// roc 2011-06 008a2bb0  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a2bb0
//
// 008a2bb0  56                   push esi
// 008a2bb1  57                   push edi
// 008a2bb2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008a2bb6  8b4718               mov eax, dword ptr [edi + 0x18]
// 008a2bb9  f7d0                 not eax
// 008a2bbb  8bf1                 mov esi, ecx
// 008a2bbd  a801                 test al, 1
// 008a2bbf  741e                 je 0x8a2bdf
// 008a2bc1  8b4e08               mov ecx, dword ptr [esi + 8]
// 008a2bc4  51                   push ecx
// 008a2bc5  8bcf                 mov ecx, edi
// 008a2bc7  e82c80f6ff           call 0x80abf8
// 008a2bcc  8b5608               mov edx, dword ptr [esi + 8]
// 008a2bcf  8b4604               mov eax, dword ptr [esi + 4]
// 008a2bd2  52                   push edx
// 008a2bd3  50                   push eax
// 008a2bd4  57                   push edi
// 008a2bd5  e846fcffff           call 0x8a2820
// 008a2bda  5f                   pop edi
// 008a2bdb  5e                   pop esi
// 008a2bdc  c20400               ret 4
// 008a2bdf  8bcf                 mov ecx, edi
// 008a2be1  e80c80f6ff           call 0x80abf2
// 008a2be6  6aff                 push -1
// 008a2be8  50                   push eax
// 008a2be9  8bce                 mov ecx, esi
// 008a2beb  e860f9ffff           call 0x8a2550
// 008a2bf0  8b5608               mov edx, dword ptr [esi + 8]
// 008a2bf3  8b4604               mov eax, dword ptr [esi + 4]
// 008a2bf6  52                   push edx
// 008a2bf7  50                   push eax
// 008a2bf8  57                   push edi
// 008a2bf9  e822fcffff           call 0x8a2820
// 008a2bfe  5f                   pop edi
// 008a2bff  5e                   pop esi
// 008a2c00  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
