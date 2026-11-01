// from server: 100% by auto
// roc 2009-12 007f91e0  unit: CXTPControlComboBoxAutoCompleteWnd  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f91e0
//
// 007f91e0  817c24080a020000     cmp dword ptr [esp + 8], 0x20a
// 007f91e8  750e                 jne 0x7f91f8
// 007f91ea  83790800             cmp dword ptr [ecx + 8], 0
// 007f91ee  7408                 je 0x7f91f8
// 007f91f0  b802000000           mov eax, 2
// 007f91f5  c21400               ret 0x14
// 007f91f8  33c0                 xor eax, eax
// 007f91fa  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxAutoCompleteWnd@@EAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
