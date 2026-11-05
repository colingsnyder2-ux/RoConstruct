// from server: 100% by auto
// roc 2010-06 00867a30  unit: CXTPDockingPaneTabbedContainer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00867a30
//
// 00867a30  837c240800           cmp dword ptr [esp + 8], 0
// 00867a35  8b442404             mov eax, dword ptr [esp + 4]
// 00867a39  7404                 je 0x867a3f
// 00867a3b  83c020               add eax, 0x20
// 00867a3e  c3                   ret 
// 00867a3f  83c024               add eax, 0x24
// 00867a42  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMaxSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
