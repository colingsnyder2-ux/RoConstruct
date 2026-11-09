// from server: 100% by auto
// roc 2010-06 008837e0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008837e0
//
// 008837e0  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 008837e3  33c0                 xor eax, eax
// 008837e5  85d2                 test edx, edx
// 008837e7  7e29                 jle 0x883812
// 008837e9  8da42400000000       lea esp, [esp]
// 008837f0  85c0                 test eax, eax
// 008837f2  7c11                 jl 0x883805
// 008837f4  3bc2                 cmp eax, edx
// 008837f6  7d0d                 jge 0x883805
// 008837f8  3b415c               cmp eax, dword ptr [ecx + 0x5c]
// 008837fb  7d1c                 jge 0x883819
// 008837fd  8b5158               mov edx, dword ptr [ecx + 0x58]
// 00883800  8b1482               mov edx, dword ptr [edx + eax*4]
// 00883803  eb02                 jmp 0x883807
// 00883805  33d2                 xor edx, edx
// 00883807  89422c               mov dword ptr [edx + 0x2c], eax
// 0088380a  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 0088380d  40                   inc eax
// 0088380e  3bc2                 cmp eax, edx
// 00883810  7cde                 jl 0x8837f0
// 00883812  8b01                 mov eax, dword ptr [ecx]
// 00883814  8b5004               mov edx, dword ptr [eax + 4]
// 00883817  ffe2                 jmp edx
// 00883819  e92e44f2ff           jmp 0x7a7c4c
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?OnItemsChanged@CXTPTabManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
