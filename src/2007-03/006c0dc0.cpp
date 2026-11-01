// from server: 100% by auto
// roc 2007-03 006c0dc0  unit: seg_006c0000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c0dc0
//
// 006c0dc0  83792000             cmp dword ptr [ecx + 0x20], 0
// 006c0dc4  741c                 je 0x6c0de2
// 006c0dc6  8b4124               mov eax, dword ptr [ecx + 0x24]
// 006c0dc9  85c0                 test eax, eax
// 006c0dcb  7415                 je 0x6c0de2
// 006c0dcd  83781804             cmp dword ptr [eax + 0x18], 4
// 006c0dd1  750f                 jne 0x6c0de2
// 006c0dd3  83b98400000000       cmp dword ptr [ecx + 0x84], 0
// 006c0dda  7406                 je 0x6c0de2
// 006c0ddc  b801000000           mov eax, 1
// 006c0de1  c3                   ret 
// 006c0de2  33c0                 xor eax, eax
// 006c0de4  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?IsValid@CXTPDockingPaneLayout@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
