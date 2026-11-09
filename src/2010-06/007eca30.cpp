// from server: 100% by auto
// roc 2010-06 007eca30  unit: CXTPDockingPaneManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007eca30
//
// 007eca30  8b442408             mov eax, dword ptr [esp + 8]
// 007eca34  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007eca38  8b542410             mov edx, dword ptr [esp + 0x10]
// 007eca3c  c70000000000         mov dword ptr [eax], 0
// 007eca42  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007eca46  c70100000000         mov dword ptr [ecx], 0
// 007eca4c  c7020a000000         mov dword ptr [edx], 0xa
// 007eca52  c7000a000000         mov dword ptr [eax], 0xa
// 007eca58  33c0                 xor eax, eax
// 007eca5a  c22000               ret 0x20
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?AccessibleLocation@CXTPDockingPaneManager@@MAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
