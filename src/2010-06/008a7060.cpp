// from server: 100% by auto
// roc 2010-06 008a7060  unit: CXTPDockingPaneAutoHidePanel  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7060
//
// 008a7060  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008a7064  8b01                 mov eax, dword ptr [ecx]
// 008a7066  8b10                 mov edx, dword ptr [eax]
// 008a7068  8911                 mov dword ptr [ecx], edx
// 008a706a  8b4008               mov eax, dword ptr [eax + 8]
// 008a706d  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetNext@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@AAPAU__POSITION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
