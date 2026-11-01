// from server: 100% by auto
// roc 2007-03 006202f0  unit: seg_00620000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006202f0
//
// 006202f0  817c24080a020000     cmp dword ptr [esp + 8], 0x20a
// 006202f8  750e                 jne 0x620308
// 006202fa  83790800             cmp dword ptr [ecx + 8], 0
// 006202fe  7408                 je 0x620308
// 00620300  b802000000           mov eax, 2
// 00620305  c21400               ret 0x14
// 00620308  33c0                 xor eax, eax
// 0062030a  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxAutoCompleteWnd@@EAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
