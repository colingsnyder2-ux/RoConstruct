// from server: 100% by auto
// roc 2009-06 007cd050  unit: CXTRegistryManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cd050
//
// 007cd050  83792000             cmp dword ptr [ecx + 0x20], 0
// 007cd054  741c                 je 0x7cd072
// 007cd056  8b4124               mov eax, dword ptr [ecx + 0x24]
// 007cd059  85c0                 test eax, eax
// 007cd05b  7415                 je 0x7cd072
// 007cd05d  83781804             cmp dword ptr [eax + 0x18], 4
// 007cd061  750f                 jne 0x7cd072
// 007cd063  83b98400000000       cmp dword ptr [ecx + 0x84], 0
// 007cd06a  7406                 je 0x7cd072
// 007cd06c  b801000000           mov eax, 1
// 007cd071  c3                   ret 
// 007cd072  33c0                 xor eax, eax
// 007cd074  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?IsValid@CXTPDockingPaneLayout@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
