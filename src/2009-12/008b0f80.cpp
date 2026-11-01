// from server: 100% by auto
// roc 2009-12 008b0f80  unit: CXTPDockingPaneTabbedContainer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0f80
//
// 008b0f80  8b4110               mov eax, dword ptr [ecx + 0x10]
// 008b0f83  85c0                 test eax, eax
// 008b0f85  740c                 je 0x8b0f93
// 008b0f87  83781805             cmp dword ptr [eax + 0x18], 5
// 008b0f8b  7506                 jne 0x8b0f93
// 008b0f8d  b801000000           mov eax, 1
// 008b0f92  c3                   ret 
// 008b0f93  33c0                 xor eax, eax
// 008b0f95  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?IsHidden@CXTPDockingPaneTabbedContainer@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
