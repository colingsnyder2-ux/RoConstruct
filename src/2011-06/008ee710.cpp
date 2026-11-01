// from server: 100% by auto
// roc 2011-06 008ee710  unit: CXTColorSelectorCtrl  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ee710
//
// 008ee710  8b8158010000         mov eax, dword ptr [ecx + 0x158]
// 008ee716  85c0                 test eax, eax
// 008ee718  7414                 je 0x8ee72e
// 008ee71a  8b4020               mov eax, dword ptr [eax + 0x20]
// 008ee71d  50                   push eax
// 008ee71e  ff15ec1ba400         call dword ptr [0xa41bec]
// 008ee724  85c0                 test eax, eax
// 008ee726  7406                 je 0x8ee72e
// 008ee728  b801000000           mov eax, 1
// 008ee72d  c3                   ret 
// 008ee72e  33c0                 xor eax, eax
// 008ee730  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?IsColorDlgVisible@CXTColorSelectorCtrl@@QAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
