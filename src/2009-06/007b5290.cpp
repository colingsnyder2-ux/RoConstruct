// from server: 100% by auto
// roc 2009-06 007b5290  unit: UtagACCEL::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b5290
//
// 007b5290  56                   push esi
// 007b5291  57                   push edi
// 007b5292  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007b5296  8b4718               mov eax, dword ptr [edi + 0x18]
// 007b5299  f7d0                 not eax
// 007b529b  8bf1                 mov esi, ecx
// 007b529d  a801                 test al, 1
// 007b529f  741e                 je 0x7b52bf
// 007b52a1  8b4e08               mov ecx, dword ptr [esi + 8]
// 007b52a4  51                   push ecx
// 007b52a5  8bcf                 mov ecx, edi
// 007b52a7  e81a43f6ff           call 0x7195c6
// 007b52ac  8b5608               mov edx, dword ptr [esi + 8]
// 007b52af  8b4604               mov eax, dword ptr [esi + 4]
// 007b52b2  52                   push edx
// 007b52b3  50                   push eax
// 007b52b4  57                   push edi
// 007b52b5  e856f9ffff           call 0x7b4c10
// 007b52ba  5f                   pop edi
// 007b52bb  5e                   pop esi
// 007b52bc  c20400               ret 4
// 007b52bf  8bcf                 mov ecx, edi
// 007b52c1  e8fa42f6ff           call 0x7195c0
// 007b52c6  6aff                 push -1
// 007b52c8  50                   push eax
// 007b52c9  8bce                 mov ecx, esi
// 007b52cb  e820f1ffff           call 0x7b43f0
// 007b52d0  8b5608               mov edx, dword ptr [esi + 8]
// 007b52d3  8b4604               mov eax, dword ptr [esi + 4]
// 007b52d6  52                   push edx
// 007b52d7  50                   push eax
// 007b52d8  57                   push edi
// 007b52d9  e832f9ffff           call 0x7b4c10
// 007b52de  5f                   pop edi
// 007b52df  5e                   pop esi
// 007b52e0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
