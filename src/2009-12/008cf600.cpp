// from server: 100% by auto
// roc 2009-12 008cf600  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cf600
//
// 008cf600  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 008cf603  33c0                 xor eax, eax
// 008cf605  85d2                 test edx, edx
// 008cf607  7e29                 jle 0x8cf632
// 008cf609  8da42400000000       lea esp, [esp]
// 008cf610  85c0                 test eax, eax
// 008cf612  7c11                 jl 0x8cf625
// 008cf614  3bc2                 cmp eax, edx
// 008cf616  7d0d                 jge 0x8cf625
// 008cf618  3b415c               cmp eax, dword ptr [ecx + 0x5c]
// 008cf61b  7d1c                 jge 0x8cf639
// 008cf61d  8b5158               mov edx, dword ptr [ecx + 0x58]
// 008cf620  8b1482               mov edx, dword ptr [edx + eax*4]
// 008cf623  eb02                 jmp 0x8cf627
// 008cf625  33d2                 xor edx, edx
// 008cf627  89422c               mov dword ptr [edx + 0x2c], eax
// 008cf62a  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 008cf62d  40                   inc eax
// 008cf62e  3bc2                 cmp eax, edx
// 008cf630  7cde                 jl 0x8cf610
// 008cf632  8b01                 mov eax, dword ptr [ecx]
// 008cf634  8b5004               mov edx, dword ptr [eax + 4]
// 008cf637  ffe2                 jmp edx
// 008cf639  e9ce44f2ff           jmp 0x7f3b0c
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?OnItemsChanged@CXTPTabManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
