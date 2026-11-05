// from server: 100% by auto
// roc 2010-06 0085bf90  unit: CXTRegistryManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085bf90
//
// 0085bf90  83792000             cmp dword ptr [ecx + 0x20], 0
// 0085bf94  741c                 je 0x85bfb2
// 0085bf96  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0085bf99  85c0                 test eax, eax
// 0085bf9b  7415                 je 0x85bfb2
// 0085bf9d  83781804             cmp dword ptr [eax + 0x18], 4
// 0085bfa1  750f                 jne 0x85bfb2
// 0085bfa3  83b98400000000       cmp dword ptr [ecx + 0x84], 0
// 0085bfaa  7406                 je 0x85bfb2
// 0085bfac  b801000000           mov eax, 1
// 0085bfb1  c3                   ret 
// 0085bfb2  33c0                 xor eax, eax
// 0085bfb4  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?IsValid@CXTPDockingPaneLayout@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
