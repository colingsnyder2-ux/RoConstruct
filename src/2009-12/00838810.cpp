// from server: 100% by auto
// roc 2009-12 00838810  unit: CXTPDockingPaneManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00838810
//
// 00838810  8b442408             mov eax, dword ptr [esp + 8]
// 00838814  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00838818  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083881c  c70000000000         mov dword ptr [eax], 0
// 00838822  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00838826  c70100000000         mov dword ptr [ecx], 0
// 0083882c  c7020a000000         mov dword ptr [edx], 0xa
// 00838832  c7000a000000         mov dword ptr [eax], 0xa
// 00838838  33c0                 xor eax, eax
// 0083883a  c22000               ret 0x20
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?AccessibleLocation@CXTPDockingPaneManager@@MAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
