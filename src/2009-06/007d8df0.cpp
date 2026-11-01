// from server: 100% by auto
// roc 2009-06 007d8df0  unit: CXTPDockingPaneTabbedContainer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d8df0
//
// 007d8df0  837c240800           cmp dword ptr [esp + 8], 0
// 007d8df5  8b442404             mov eax, dword ptr [esp + 4]
// 007d8df9  7404                 je 0x7d8dff
// 007d8dfb  83c018               add eax, 0x18
// 007d8dfe  c3                   ret 
// 007d8dff  83c01c               add eax, 0x1c
// 007d8e02  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMinSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
