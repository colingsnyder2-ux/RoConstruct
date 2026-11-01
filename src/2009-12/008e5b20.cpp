// from server: 100% by auto
// roc 2009-12 008e5b20  unit: CXTColorSelectorCtrl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5b20
//
// 008e5b20  56                   push esi
// 008e5b21  57                   push edi
// 008e5b22  8bf1                 mov esi, ecx
// 008e5b24  e807e3f0ff           call 0x7f3e30
// 008e5b29  6a00                 push 0
// 008e5b2b  8bf8                 mov edi, eax
// 008e5b2d  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e5b30  6a00                 push 0
// 008e5b32  50                   push eax
// 008e5b33  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e5b39  8bc7                 mov eax, edi
// 008e5b3b  5f                   pop edi
// 008e5b3c  5e                   pop esi
// 008e5b3d  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnDefaultAndInvalidate@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
