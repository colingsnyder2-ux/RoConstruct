// from server: 100% by auto
// roc 2010-06 00865400  unit: CXTPDockingPaneTabbedContainer  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00865400
//
// 00865400  56                   push esi
// 00865401  8bf1                 mov esi, ecx
// 00865403  8b4620               mov eax, dword ptr [esi + 0x20]
// 00865406  85c0                 test eax, eax
// 00865408  743e                 je 0x865448
// 0086540a  50                   push eax
// 0086540b  ff154cba9e00         call dword ptr [0x9eba4c]
// 00865411  50                   push eax
// 00865412  e85328f4ff           call 0x7a7c6a
// 00865417  50                   push eax
// 00865418  e8d388ffff           call 0x85dcf0
// 0086541d  50                   push eax
// 0086541e  e85b29f4ff           call 0x7a7d7e
// 00865423  83c408               add esp, 8
// 00865426  85c0                 test eax, eax
// 00865428  751e                 jne 0x865448
// 0086542a  83be0401000001       cmp dword ptr [esi + 0x104], 1
// 00865431  7f0e                 jg 0x865441
// 00865433  8d4e54               lea ecx, [esi + 0x54]
// 00865436  e8e5f4ffff           call 0x864920
// 0086543b  83783000             cmp dword ptr [eax + 0x30], 0
// 0086543f  7407                 je 0x865448
// 00865441  b801000000           mov eax, 1
// 00865446  5e                   pop esi
// 00865447  c3                   ret 
// 00865448  33c0                 xor eax, eax
// 0086544a  5e                   pop esi
// 0086544b  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?IsTabsVisible@CXTPDockingPaneTabbedContainer@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
