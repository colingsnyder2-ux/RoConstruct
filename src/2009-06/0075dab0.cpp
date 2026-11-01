// from server: 100% by auto
// roc 2009-06 0075dab0  unit: CXTPDockingPaneManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075dab0
//
// 0075dab0  8b442408             mov eax, dword ptr [esp + 8]
// 0075dab4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0075dab8  8b542410             mov edx, dword ptr [esp + 0x10]
// 0075dabc  c70000000000         mov dword ptr [eax], 0
// 0075dac2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0075dac6  c70100000000         mov dword ptr [ecx], 0
// 0075dacc  c7020a000000         mov dword ptr [edx], 0xa
// 0075dad2  c7000a000000         mov dword ptr [eax], 0xa
// 0075dad8  33c0                 xor eax, eax
// 0075dada  c22000               ret 0x20
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?AccessibleLocation@CXTPDockingPaneManager@@MAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
