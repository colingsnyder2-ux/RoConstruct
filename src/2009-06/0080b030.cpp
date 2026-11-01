// from server: 100% by auto
// roc 2009-06 0080b030  unit: CXTCaptionButton  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b030
//
// 0080b030  56                   push esi
// 0080b031  57                   push edi
// 0080b032  8bf1                 mov esi, ecx
// 0080b034  e8cfdff0ff           call 0x719008
// 0080b039  6a00                 push 0
// 0080b03b  8bf8                 mov edi, eax
// 0080b03d  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080b040  6a00                 push 0
// 0080b042  50                   push eax
// 0080b043  ff157cee8900         call dword ptr [0x89ee7c]
// 0080b049  8bc7                 mov eax, edi
// 0080b04b  5f                   pop edi
// 0080b04c  5e                   pop esi
// 0080b04d  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnDefaultAndInvalidate@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
