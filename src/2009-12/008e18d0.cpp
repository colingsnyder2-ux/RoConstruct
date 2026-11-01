// from server: 100% by auto
// roc 2009-12 008e18d0  unit: CXTColorSelectorCtrl  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e18d0
//
// 008e18d0  8b8158010000         mov eax, dword ptr [ecx + 0x158]
// 008e18d6  85c0                 test eax, eax
// 008e18d8  7414                 je 0x8e18ee
// 008e18da  8b4020               mov eax, dword ptr [eax + 0x20]
// 008e18dd  50                   push eax
// 008e18de  ff1584cc9800         call dword ptr [0x98cc84]
// 008e18e4  85c0                 test eax, eax
// 008e18e6  7406                 je 0x8e18ee
// 008e18e8  b801000000           mov eax, 1
// 008e18ed  c3                   ret 
// 008e18ee  33c0                 xor eax, eax
// 008e18f0  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?IsColorDlgVisible@CXTColorSelectorCtrl@@QAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
