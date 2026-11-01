// from server: 100% by auto
// roc 2011-06 008c2850  unit: CXTPDockingPaneTabbedContainer  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008c2850
//
// 008c2850  56                   push esi
// 008c2851  8bf1                 mov esi, ecx
// 008c2853  8b4620               mov eax, dword ptr [esi + 0x20]
// 008c2856  85c0                 test eax, eax
// 008c2858  743e                 je 0x8c2898
// 008c285a  50                   push eax
// 008c285b  ff15b819a400         call dword ptr [0xa419b8]
// 008c2861  50                   push eax
// 008c2862  e8c17af4ff           call 0x80a328
// 008c2867  50                   push eax
// 008c2868  e85386ffff           call 0x8baec0
// 008c286d  50                   push eax
// 008c286e  e8c97bf4ff           call 0x80a43c
// 008c2873  83c408               add esp, 8
// 008c2876  85c0                 test eax, eax
// 008c2878  751e                 jne 0x8c2898
// 008c287a  83be0401000001       cmp dword ptr [esi + 0x104], 1
// 008c2881  7f0e                 jg 0x8c2891
// 008c2883  8d4e54               lea ecx, [esi + 0x54]
// 008c2886  e8e5f4ffff           call 0x8c1d70
// 008c288b  83783000             cmp dword ptr [eax + 0x30], 0
// 008c288f  7407                 je 0x8c2898
// 008c2891  b801000000           mov eax, 1
// 008c2896  5e                   pop esi
// 008c2897  c3                   ret 
// 008c2898  33c0                 xor eax, eax
// 008c289a  5e                   pop esi
// 008c289b  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?IsTabsVisible@CXTPDockingPaneTabbedContainer@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
