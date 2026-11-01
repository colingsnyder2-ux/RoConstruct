// from server: 100% by auto
// roc 2009-06 0071afd0  unit: CXTPControlComboBoxAutoCompleteWnd  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071afd0
//
// 0071afd0  817c24080a020000     cmp dword ptr [esp + 8], 0x20a
// 0071afd8  750e                 jne 0x71afe8
// 0071afda  83790800             cmp dword ptr [ecx + 8], 0
// 0071afde  7408                 je 0x71afe8
// 0071afe0  b802000000           mov eax, 2
// 0071afe5  c21400               ret 0x14
// 0071afe8  33c0                 xor eax, eax
// 0071afea  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxAutoCompleteWnd@@EAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
