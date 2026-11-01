// from server: 100% by auto
// roc 2009-06 0075f920  unit: CXTPDockingPaneManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075f920
//
// 0075f920  8b442408             mov eax, dword ptr [esp + 8]
// 0075f924  56                   push esi
// 0075f925  8bf1                 mov esi, ecx
// 0075f927  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0075f92b  50                   push eax
// 0075f92c  51                   push ecx
// 0075f92d  8bce                 mov ecx, esi
// 0075f92f  e88cf1ffff           call 0x75eac0
// 0075f934  8bce                 mov ecx, esi
// 0075f936  e815e3ffff           call 0x75dc50
// 0075f93b  5e                   pop esi
// 0075f93c  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?AttachPane@CXTPDockingPaneManager@@QAEXPAVCXTPDockingPaneBase@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
