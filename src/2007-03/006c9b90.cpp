// from server: 100% by auto
// roc 2007-03 006c9b90  unit: seg_006c0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9b90
//
// 006c9b90  8b4110               mov eax, dword ptr [ecx + 0x10]
// 006c9b93  85c0                 test eax, eax
// 006c9b95  740c                 je 0x6c9ba3
// 006c9b97  83781805             cmp dword ptr [eax + 0x18], 5
// 006c9b9b  7506                 jne 0x6c9ba3
// 006c9b9d  b801000000           mov eax, 1
// 006c9ba2  c3                   ret 
// 006c9ba3  33c0                 xor eax, eax
// 006c9ba5  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?IsHidden@CXTPDockingPaneTabbedContainer@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
