// from server: 100% by auto
// roc 2010-06 00808f90  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808f90
//
// 00808f90  33c0                 xor eax, eax
// 00808f92  394158               cmp dword ptr [ecx + 0x58], eax
// 00808f95  7406                 je 0x808f9d
// 00808f97  894158               mov dword ptr [ecx + 0x58], eax
// 00808f9a  89415c               mov dword ptr [ecx + 0x5c], eax
// 00808f9d  8b01                 mov eax, dword ptr [ecx]
// 00808f9f  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 00808fa5  ffe2                 jmp edx
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnIdleUpdateCmdUI@CXTPTabClientWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
