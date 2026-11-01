// from server: 100% by auto
// roc 2009-12 0083a6e0  unit: CXTPDockingPaneManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083a6e0
//
// 0083a6e0  8b442408             mov eax, dword ptr [esp + 8]
// 0083a6e4  56                   push esi
// 0083a6e5  8bf1                 mov esi, ecx
// 0083a6e7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0083a6eb  50                   push eax
// 0083a6ec  51                   push ecx
// 0083a6ed  8bce                 mov ecx, esi
// 0083a6ef  e88cf1ffff           call 0x839880
// 0083a6f4  8bce                 mov ecx, esi
// 0083a6f6  e815e3ffff           call 0x838a10
// 0083a6fb  5e                   pop esi
// 0083a6fc  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?AttachPane@CXTPDockingPaneManager@@QAEXPAVCXTPDockingPaneBase@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
