// from server: 100% by auto
// roc 2010-06 00883820  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00883820
//
// 00883820  8b515c               mov edx, dword ptr [ecx + 0x5c]
// 00883823  85d2                 test edx, edx
// 00883825  7430                 je 0x883857
// 00883827  8b442404             mov eax, dword ptr [esp + 4]
// 0088382b  85c0                 test eax, eax
// 0088382d  7d04                 jge 0x883833
// 0088382f  33c0                 xor eax, eax
// 00883831  eb0b                 jmp 0x88383e
// 00883833  3bc2                 cmp eax, edx
// 00883835  7c03                 jl 0x88383a
// 00883837  8d42ff               lea eax, [edx - 1]
// 0088383a  85c0                 test eax, eax
// 0088383c  7c0c                 jl 0x88384a
// 0088383e  3bc2                 cmp eax, edx
// 00883840  7d08                 jge 0x88384a
// 00883842  8b5158               mov edx, dword ptr [ecx + 0x58]
// 00883845  8b0482               mov eax, dword ptr [edx + eax*4]
// 00883848  eb02                 jmp 0x88384c
// 0088384a  33c0                 xor eax, eax
// 0088384c  8b11                 mov edx, dword ptr [ecx]
// 0088384e  89442404             mov dword ptr [esp + 4], eax
// 00883852  8b4220               mov eax, dword ptr [edx + 0x20]
// 00883855  ffe0                 jmp eax
// 00883857  8b11                 mov edx, dword ptr [ecx]
// 00883859  8b4220               mov eax, dword ptr [edx + 0x20]
// 0088385c  c744240400000000     mov dword ptr [esp + 4], 0
// 00883864  ffe0                 jmp eax
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetCurSel@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
