// from server: 100% by auto
// roc 2010-06 00867a10  unit: CXTPDockingPaneTabbedContainer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00867a10
//
// 00867a10  837c240800           cmp dword ptr [esp + 8], 0
// 00867a15  8b442404             mov eax, dword ptr [esp + 4]
// 00867a19  7404                 je 0x867a1f
// 00867a1b  83c018               add eax, 0x18
// 00867a1e  c3                   ret 
// 00867a1f  83c01c               add eax, 0x1c
// 00867a22  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMinSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
