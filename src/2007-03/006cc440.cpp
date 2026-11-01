// from server: 100% by auto
// roc 2007-03 006cc440  unit: seg_006c0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006cc440
//
// 006cc440  837c240800           cmp dword ptr [esp + 8], 0
// 006cc445  8b442404             mov eax, dword ptr [esp + 4]
// 006cc449  7404                 je 0x6cc44f
// 006cc44b  83c018               add eax, 0x18
// 006cc44e  c3                   ret 
// 006cc44f  83c01c               add eax, 0x1c
// 006cc452  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMinSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
