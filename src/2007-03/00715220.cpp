// from server: 100% by auto
// roc 2007-03 00715220  unit: seg_00710000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00715220
//
// 00715220  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00715224  8b01                 mov eax, dword ptr [ecx]
// 00715226  8b10                 mov edx, dword ptr [eax]
// 00715228  8911                 mov dword ptr [ecx], edx
// 0071522a  8b4008               mov eax, dword ptr [eax + 8]
// 0071522d  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetNext@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@AAPAU__POSITION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
