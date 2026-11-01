// from server: 100% by auto
// roc 2007-08 00689bd0  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689bd0
//
// 00689bd0  33c0                 xor eax, eax
// 00689bd2  394158               cmp dword ptr [ecx + 0x58], eax
// 00689bd5  7406                 je 0x689bdd
// 00689bd7  894158               mov dword ptr [ecx + 0x58], eax
// 00689bda  89415c               mov dword ptr [ecx + 0x5c], eax
// 00689bdd  8b01                 mov eax, dword ptr [ecx]
// 00689bdf  8b903c010000         mov edx, dword ptr [eax + 0x13c]
// 00689be5  ffe2                 jmp edx
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnIdleUpdateCmdUI@CXTPTabClientWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
