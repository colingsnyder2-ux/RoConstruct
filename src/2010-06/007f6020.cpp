// from server: 100% by auto
// roc 2010-06 007f6020  unit: CXTPPopupBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f6020
//
// 007f6020  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007f6023  85c0                 test eax, eax
// 007f6025  7411                 je 0x7f6038
// 007f6027  50                   push eax
// 007f6028  ff15e8bb9e00         call dword ptr [0x9ebbe8]
// 007f602e  85c0                 test eax, eax
// 007f6030  7406                 je 0x7f6038
// 007f6032  b801000000           mov eax, 1
// 007f6037  c3                   ret 
// 007f6038  33c0                 xor eax, eax
// 007f603a  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?IsVisible@CXTPPopupBar@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
