// from server: 100% by auto
// roc 2010-06 007ee840  unit: CXTPDockingPaneManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ee840
//
// 007ee840  8b442408             mov eax, dword ptr [esp + 8]
// 007ee844  56                   push esi
// 007ee845  8bf1                 mov esi, ecx
// 007ee847  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007ee84b  50                   push eax
// 007ee84c  51                   push ecx
// 007ee84d  8bce                 mov ecx, esi
// 007ee84f  e88cf1ffff           call 0x7ed9e0
// 007ee854  8bce                 mov ecx, esi
// 007ee856  e815e3ffff           call 0x7ecb70
// 007ee85b  5e                   pop esi
// 007ee85c  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?AttachPane@CXTPDockingPaneManager@@QAEXPAVCXTPDockingPaneBase@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
