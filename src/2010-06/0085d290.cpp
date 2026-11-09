// from server: 100% by auto
// roc 2010-06 0085d290  unit: CXTPDockingPaneLayout  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085d290
//
// 0085d290  8b442404             mov eax, dword ptr [esp + 4]
// 0085d294  83782800             cmp dword ptr [eax + 0x28], 0
// 0085d298  7409                 je 0x85d2a3
// 0085d29a  89442404             mov dword ptr [esp + 4], eax
// 0085d29e  e9bdf9ffff           jmp 0x85cc60
// 0085d2a3  50                   push eax
// 0085d2a4  e8e7fcffff           call 0x85cf90
// 0085d2a9  b801000000           mov eax, 1
// 0085d2ae  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?DoPropExchange@CXTPDockingPaneLayout@@QAEHPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
