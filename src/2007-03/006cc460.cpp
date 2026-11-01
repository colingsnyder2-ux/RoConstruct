// from server: 100% by auto
// roc 2007-03 006cc460  unit: seg_006c0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006cc460
//
// 006cc460  837c240800           cmp dword ptr [esp + 8], 0
// 006cc465  8b442404             mov eax, dword ptr [esp + 4]
// 006cc469  7404                 je 0x6cc46f
// 006cc46b  83c020               add eax, 0x20
// 006cc46e  c3                   ret 
// 006cc46f  83c024               add eax, 0x24
// 006cc472  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMaxSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
