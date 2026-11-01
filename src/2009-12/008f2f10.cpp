// from server: 100% by auto
// roc 2009-12 008f2f10  unit: CXTPDockingPaneAutoHidePanel  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2f10
//
// 008f2f10  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008f2f14  8b01                 mov eax, dword ptr [ecx]
// 008f2f16  8b10                 mov edx, dword ptr [eax]
// 008f2f18  8911                 mov dword ptr [ecx], edx
// 008f2f1a  8b4008               mov eax, dword ptr [eax + 8]
// 008f2f1d  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetNext@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@AAPAU__POSITION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
