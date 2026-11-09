// from server: 100% by auto
// roc 2010-06 00895b30  unit: CXTColorSelectorCtrl  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00895b30
//
// 00895b30  8b8158010000         mov eax, dword ptr [ecx + 0x158]
// 00895b36  85c0                 test eax, eax
// 00895b38  7414                 je 0x895b4e
// 00895b3a  8b4020               mov eax, dword ptr [eax + 0x20]
// 00895b3d  50                   push eax
// 00895b3e  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00895b44  85c0                 test eax, eax
// 00895b46  7406                 je 0x895b4e
// 00895b48  b801000000           mov eax, 1
// 00895b4d  c3                   ret 
// 00895b4e  33c0                 xor eax, eax
// 00895b50  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?IsColorDlgVisible@CXTColorSelectorCtrl@@QAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
