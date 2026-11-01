// from server: 100% by auto
// roc 2009-06 007d8e10  unit: CXTPDockingPaneTabbedContainer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d8e10
//
// 007d8e10  837c240800           cmp dword ptr [esp + 8], 0
// 007d8e15  8b442404             mov eax, dword ptr [esp + 4]
// 007d8e19  7404                 je 0x7d8e1f
// 007d8e1b  83c020               add eax, 0x20
// 007d8e1e  c3                   ret 
// 007d8e1f  83c024               add eax, 0x24
// 007d8e22  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMaxSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
