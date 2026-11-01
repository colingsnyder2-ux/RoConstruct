// from server: 100% by auto
// roc 2009-06 007f4a50  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f4a50
//
// 007f4a50  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 007f4a53  33c0                 xor eax, eax
// 007f4a55  85d2                 test edx, edx
// 007f4a57  7e29                 jle 0x7f4a82
// 007f4a59  8da42400000000       lea esp, [esp]
// 007f4a60  85c0                 test eax, eax
// 007f4a62  7c11                 jl 0x7f4a75
// 007f4a64  3bc2                 cmp eax, edx
// 007f4a66  7d0d                 jge 0x7f4a75
// 007f4a68  3b415c               cmp eax, dword ptr [ecx + 0x5c]
// 007f4a6b  7d1c                 jge 0x7f4a89
// 007f4a6d  8b5158               mov edx, dword ptr [ecx + 0x58]
// 007f4a70  8b1482               mov edx, dword ptr [edx + eax*4]
// 007f4a73  eb02                 jmp 0x7f4a77
// 007f4a75  33d2                 xor edx, edx
// 007f4a77  89422c               mov dword ptr [edx + 0x2c], eax
// 007f4a7a  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 007f4a7d  40                   inc eax
// 007f4a7e  3bc2                 cmp eax, edx
// 007f4a80  7cde                 jl 0x7f4a60
// 007f4a82  8b01                 mov eax, dword ptr [ecx]
// 007f4a84  8b5004               mov edx, dword ptr [eax + 4]
// 007f4a87  ffe2                 jmp edx
// 007f4a89  e95642f2ff           jmp 0x718ce4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?OnItemsChanged@CXTPTabManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
