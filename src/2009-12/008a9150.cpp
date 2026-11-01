// from server: 100% by auto
// roc 2009-12 008a9150  unit: CXTPDockingPaneLayout  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a9150
//
// 008a9150  8b442404             mov eax, dword ptr [esp + 4]
// 008a9154  83782800             cmp dword ptr [eax + 0x28], 0
// 008a9158  7409                 je 0x8a9163
// 008a915a  89442404             mov dword ptr [esp + 4], eax
// 008a915e  e9bdf9ffff           jmp 0x8a8b20
// 008a9163  50                   push eax
// 008a9164  e8e7fcffff           call 0x8a8e50
// 008a9169  b801000000           mov eax, 1
// 008a916e  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?DoPropExchange@CXTPDockingPaneLayout@@QAEHPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
