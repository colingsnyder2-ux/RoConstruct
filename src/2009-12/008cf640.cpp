// from server: 100% by auto
// roc 2009-12 008cf640  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cf640
//
// 008cf640  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 008cf643  85d2                 test edx, edx
// 008cf645  7430                 je 0x8cf677
// 008cf647  8b442404             mov eax, dword ptr [esp + 4]
// 008cf64b  85c0                 test eax, eax
// 008cf64d  7d04                 jge 0x8cf653
// 008cf64f  33c0                 xor eax, eax
// 008cf651  eb0b                 jmp 0x8cf65e
// 008cf653  3bc2                 cmp eax, edx
// 008cf655  7c03                 jl 0x8cf65a
// 008cf657  8d42ff               lea eax, [edx - 1]
// 008cf65a  85c0                 test eax, eax
// 008cf65c  7c0c                 jl 0x8cf66a
// 008cf65e  3bc2                 cmp eax, edx
// 008cf660  7d08                 jge 0x8cf66a
// 008cf662  8b5158               mov edx, dword ptr [ecx + 0x58]
// 008cf665  8b0482               mov eax, dword ptr [edx + eax*4]
// 008cf668  eb02                 jmp 0x8cf66c
// 008cf66a  33c0                 xor eax, eax
// 008cf66c  8b11                 mov edx, dword ptr [ecx]
// 008cf66e  89442404             mov dword ptr [esp + 4], eax
// 008cf672  8b4220               mov eax, dword ptr [edx + 0x20]
// 008cf675  ffe0                 jmp eax
// 008cf677  8b11                 mov edx, dword ptr [ecx]
// 008cf679  8b4220               mov eax, dword ptr [edx + 0x20]
// 008cf67c  c744240400000000     mov dword ptr [esp + 4], 0
// 008cf684  ffe0                 jmp eax
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetCurSel@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
