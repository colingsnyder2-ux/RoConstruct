// from server: 100% by auto
// roc 2009-06 0080b050  unit: CXTCaptionButton  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b050
//
// 0080b050  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0080b053  6a00                 push 0
// 0080b055  6a00                 push 0
// 0080b057  50                   push eax
// 0080b058  ff157cee8900         call dword ptr [0x89ee7c]
// 0080b05e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnInvalidate@CXTButton@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
