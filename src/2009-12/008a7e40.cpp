// from server: 100% by auto
// roc 2009-12 008a7e40  unit: CXTRegistryManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a7e40
//
// 008a7e40  83792000             cmp dword ptr [ecx + 0x20], 0
// 008a7e44  741c                 je 0x8a7e62
// 008a7e46  8b4124               mov eax, dword ptr [ecx + 0x24]
// 008a7e49  85c0                 test eax, eax
// 008a7e4b  7415                 je 0x8a7e62
// 008a7e4d  83781804             cmp dword ptr [eax + 0x18], 4
// 008a7e51  750f                 jne 0x8a7e62
// 008a7e53  83b98400000000       cmp dword ptr [ecx + 0x84], 0
// 008a7e5a  7406                 je 0x8a7e62
// 008a7e5c  b801000000           mov eax, 1
// 008a7e61  c3                   ret 
// 008a7e62  33c0                 xor eax, eax
// 008a7e64  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?IsValid@CXTPDockingPaneLayout@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
