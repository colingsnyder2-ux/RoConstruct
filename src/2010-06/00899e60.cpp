// from server: 100% by auto
// roc 2010-06 00899e60  unit: CXTColorSelectorCtrl  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899e60
//
// 00899e60  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00899e63  6a00                 push 0
// 00899e65  6a00                 push 0
// 00899e67  50                   push eax
// 00899e68  ff1578ba9e00         call dword ptr [0x9eba78]
// 00899e6e  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?OnInvalidate@CXTButton@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
