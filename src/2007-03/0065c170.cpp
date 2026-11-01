// from server: 100% by auto
// roc 2007-03 0065c170  unit: seg_00650000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065c170
//
// 0065c170  8b442408             mov eax, dword ptr [esp + 8]
// 0065c174  56                   push esi
// 0065c175  8bf1                 mov esi, ecx
// 0065c177  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065c17b  50                   push eax
// 0065c17c  51                   push ecx
// 0065c17d  8bce                 mov ecx, esi
// 0065c17f  e83cf1ffff           call 0x65b2c0
// 0065c184  8bce                 mov ecx, esi
// 0065c186  e8e5e2ffff           call 0x65a470
// 0065c18b  5e                   pop esi
// 0065c18c  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?AttachPane@CXTPDockingPaneManager@@QAEXPAVCXTPDockingPaneBase@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
