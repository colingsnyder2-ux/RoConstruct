// from server: 100% by auto
// roc 2010-06 00865060  unit: CXTPDockingPaneTabbedContainer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00865060
//
// 00865060  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00865063  85c0                 test eax, eax
// 00865065  740c                 je 0x865073
// 00865067  83781805             cmp dword ptr [eax + 0x18], 5
// 0086506b  7506                 jne 0x865073
// 0086506d  b801000000           mov eax, 1
// 00865072  c3                   ret 
// 00865073  33c0                 xor eax, eax
// 00865075  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?IsHidden@CXTPDockingPaneTabbedContainer@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
