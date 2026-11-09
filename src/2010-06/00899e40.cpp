// from server: 100% by auto
// roc 2010-06 00899e40  unit: CXTColorSelectorCtrl  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899e40
//
// 00899e40  56                   push esi
// 00899e41  57                   push edi
// 00899e42  8bf1                 mov esi, ecx
// 00899e44  e827e1f0ff           call 0x7a7f70
// 00899e49  6a00                 push 0
// 00899e4b  8bf8                 mov edi, eax
// 00899e4d  8b4620               mov eax, dword ptr [esi + 0x20]
// 00899e50  6a00                 push 0
// 00899e52  50                   push eax
// 00899e53  ff1578ba9e00         call dword ptr [0x9eba78]
// 00899e59  8bc7                 mov eax, edi
// 00899e5b  5f                   pop edi
// 00899e5c  5e                   pop esi
// 00899e5d  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?OnDefaultAndInvalidate@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
