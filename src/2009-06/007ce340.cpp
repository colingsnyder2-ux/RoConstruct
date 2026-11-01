// from server: 100% by auto
// roc 2009-06 007ce340  unit: CXTPDockingPaneLayout  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ce340
//
// 007ce340  8b442404             mov eax, dword ptr [esp + 4]
// 007ce344  83782800             cmp dword ptr [eax + 0x28], 0
// 007ce348  7409                 je 0x7ce353
// 007ce34a  89442404             mov dword ptr [esp + 4], eax
// 007ce34e  e9bdf9ffff           jmp 0x7cdd10
// 007ce353  50                   push eax
// 007ce354  e8e7fcffff           call 0x7ce040
// 007ce359  b801000000           mov eax, 1
// 007ce35e  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?DoPropExchange@CXTPDockingPaneLayout@@QAEHPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
