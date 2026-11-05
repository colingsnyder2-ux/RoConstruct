// from server: 100% by auto
// roc 2009-06 00806dc0  unit: CXTColorSelectorCtrl  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00806dc0
//
// 00806dc0  8b8158010000         mov eax, dword ptr [ecx + 0x158]
// 00806dc6  85c0                 test eax, eax
// 00806dc8  7414                 je 0x806dde
// 00806dca  8b4020               mov eax, dword ptr [eax + 0x20]
// 00806dcd  50                   push eax
// 00806dce  ff15e0ed8900         call dword ptr [0x89ede0]
// 00806dd4  85c0                 test eax, eax
// 00806dd6  7406                 je 0x806dde
// 00806dd8  b801000000           mov eax, 1
// 00806ddd  c3                   ret 
// 00806dde  33c0                 xor eax, eax
// 00806de0  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?IsColorDlgVisible@CXTColorSelectorCtrl@@QAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
