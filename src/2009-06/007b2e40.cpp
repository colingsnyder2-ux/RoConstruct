// from server: 100% by auto
// roc 2009-06 007b2e40  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2e40
//
// 007b2e40  56                   push esi
// 007b2e41  57                   push edi
// 007b2e42  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007b2e46  8b4718               mov eax, dword ptr [edi + 0x18]
// 007b2e49  f7d0                 not eax
// 007b2e4b  8bf1                 mov esi, ecx
// 007b2e4d  a801                 test al, 1
// 007b2e4f  741e                 je 0x7b2e6f
// 007b2e51  8b4e08               mov ecx, dword ptr [esi + 8]
// 007b2e54  51                   push ecx
// 007b2e55  8bcf                 mov ecx, edi
// 007b2e57  e86a67f6ff           call 0x7195c6
// 007b2e5c  8b5608               mov edx, dword ptr [esi + 8]
// 007b2e5f  8b4604               mov eax, dword ptr [esi + 4]
// 007b2e62  52                   push edx
// 007b2e63  50                   push eax
// 007b2e64  57                   push edi
// 007b2e65  e826fcffff           call 0x7b2a90
// 007b2e6a  5f                   pop edi
// 007b2e6b  5e                   pop esi
// 007b2e6c  c20400               ret 4
// 007b2e6f  8bcf                 mov ecx, edi
// 007b2e71  e84a67f6ff           call 0x7195c0
// 007b2e76  6aff                 push -1
// 007b2e78  50                   push eax
// 007b2e79  8bce                 mov ecx, esi
// 007b2e7b  e840f9ffff           call 0x7b27c0
// 007b2e80  8b5608               mov edx, dword ptr [esi + 8]
// 007b2e83  8b4604               mov eax, dword ptr [esi + 4]
// 007b2e86  52                   push edx
// 007b2e87  50                   push eax
// 007b2e88  57                   push edi
// 007b2e89  e802fcffff           call 0x7b2a90
// 007b2e8e  5f                   pop edi
// 007b2e8f  5e                   pop esi
// 007b2e90  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
