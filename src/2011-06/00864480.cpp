// from server: 100% by auto
// roc 2011-06 00864480  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00864480
//
// 00864480  33c0                 xor eax, eax
// 00864482  394158               cmp dword ptr [ecx + 0x58], eax
// 00864485  7406                 je 0x86448d
// 00864487  894158               mov dword ptr [ecx + 0x58], eax
// 0086448a  89415c               mov dword ptr [ecx + 0x5c], eax
// 0086448d  8b01                 mov eax, dword ptr [ecx]
// 0086448f  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 00864495  ffe2                 jmp edx
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnIdleUpdateCmdUI@CXTPTabClientWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
