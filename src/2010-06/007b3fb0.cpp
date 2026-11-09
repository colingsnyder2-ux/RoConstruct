// from server: 100% by auto
// roc 2010-06 007b3fb0  unit: CXTPControlComboBoxAutoCompleteWnd  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3fb0
//
// 007b3fb0  817c24080a020000     cmp dword ptr [esp + 8], 0x20a
// 007b3fb8  750e                 jne 0x7b3fc8
// 007b3fba  83790800             cmp dword ptr [ecx + 8], 0
// 007b3fbe  7408                 je 0x7b3fc8
// 007b3fc0  b802000000           mov eax, 2
// 007b3fc5  c21400               ret 0x14
// 007b3fc8  33c0                 xor eax, eax
// 007b3fca  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxAutoCompleteWnd@@EAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
