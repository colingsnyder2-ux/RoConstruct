// from server: 100% by auto
// roc 2009-12 008b3920  unit: CXTPDockingPaneTabbedContainer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b3920
//
// 008b3920  837c240800           cmp dword ptr [esp + 8], 0
// 008b3925  8b442404             mov eax, dword ptr [esp + 4]
// 008b3929  7404                 je 0x8b392f
// 008b392b  83c018               add eax, 0x18
// 008b392e  c3                   ret 
// 008b392f  83c01c               add eax, 0x1c
// 008b3932  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMinSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
