// from server: 100% by auto
// roc 2009-06 007f4a90  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f4a90
//
// 007f4a90  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 007f4a93  85d2                 test edx, edx
// 007f4a95  7430                 je 0x7f4ac7
// 007f4a97  8b442404             mov eax, dword ptr [esp + 4]
// 007f4a9b  85c0                 test eax, eax
// 007f4a9d  7d04                 jge 0x7f4aa3
// 007f4a9f  33c0                 xor eax, eax
// 007f4aa1  eb0b                 jmp 0x7f4aae
// 007f4aa3  3bc2                 cmp eax, edx
// 007f4aa5  7c03                 jl 0x7f4aaa
// 007f4aa7  8d42ff               lea eax, [edx - 1]
// 007f4aaa  85c0                 test eax, eax
// 007f4aac  7c0c                 jl 0x7f4aba
// 007f4aae  3bc2                 cmp eax, edx
// 007f4ab0  7d08                 jge 0x7f4aba
// 007f4ab2  8b5158               mov edx, dword ptr [ecx + 0x58]
// 007f4ab5  8b0482               mov eax, dword ptr [edx + eax*4]
// 007f4ab8  eb02                 jmp 0x7f4abc
// 007f4aba  33c0                 xor eax, eax
// 007f4abc  8b11                 mov edx, dword ptr [ecx]
// 007f4abe  89442404             mov dword ptr [esp + 4], eax
// 007f4ac2  8b4220               mov eax, dword ptr [edx + 0x20]
// 007f4ac5  ffe0                 jmp eax
// 007f4ac7  8b11                 mov edx, dword ptr [ecx]
// 007f4ac9  8b4220               mov eax, dword ptr [edx + 0x20]
// 007f4acc  c744240400000000     mov dword ptr [esp + 4], 0
// 007f4ad4  ffe0                 jmp eax
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetCurSel@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
