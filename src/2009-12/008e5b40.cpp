// from server: 100% by auto
// roc 2009-12 008e5b40  unit: CXTColorSelectorCtrl  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5b40
//
// 008e5b40  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008e5b43  6a00                 push 0
// 008e5b45  6a00                 push 0
// 008e5b47  50                   push eax
// 008e5b48  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e5b4e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnInvalidate@CXTButton@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
