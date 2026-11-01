// from server: 100% by auto
// roc 2009-06 007d6440  unit: CXTPDockingPaneTabbedContainer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d6440
//
// 007d6440  8b4110               mov eax, dword ptr [ecx + 0x10]
// 007d6443  85c0                 test eax, eax
// 007d6445  740c                 je 0x7d6453
// 007d6447  83781805             cmp dword ptr [eax + 0x18], 5
// 007d644b  7506                 jne 0x7d6453
// 007d644d  b801000000           mov eax, 1
// 007d6452  c3                   ret 
// 007d6453  33c0                 xor eax, eax
// 007d6455  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?IsHidden@CXTPDockingPaneTabbedContainer@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
