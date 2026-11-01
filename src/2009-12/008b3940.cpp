// from server: 100% by auto
// roc 2009-12 008b3940  unit: CXTPDockingPaneTabbedContainer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b3940
//
// 008b3940  837c240800           cmp dword ptr [esp + 8], 0
// 008b3945  8b442404             mov eax, dword ptr [esp + 4]
// 008b3949  7404                 je 0x8b394f
// 008b394b  83c020               add eax, 0x20
// 008b394e  c3                   ret 
// 008b394f  83c024               add eax, 0x24
// 008b3952  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMaxSize@CXTPDockingPaneSplitterContainer@@CAAAJPAUtagMINMAXINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
