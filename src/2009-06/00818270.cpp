// from server: 100% by auto
// roc 2009-06 00818270  unit: CXTPDockingPaneAutoHidePanel  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00818270
//
// 00818270  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00818274  8b01                 mov eax, dword ptr [ecx]
// 00818276  8b10                 mov edx, dword ptr [eax]
// 00818278  8911                 mov dword ptr [ecx], edx
// 0081827a  8b4008               mov eax, dword ptr [eax + 8]
// 0081827d  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetNext@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@AAPAU__POSITION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
