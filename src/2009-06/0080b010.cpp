// from server: 100% by auto
// roc 2009-06 0080b010  unit: CXTCaptionButton  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b010
//
// 0080b010  56                   push esi
// 0080b011  8bf1                 mov esi, ecx
// 0080b013  e8f0dff0ff           call 0x719008
// 0080b018  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080b01b  6a00                 push 0
// 0080b01d  6a00                 push 0
// 0080b01f  50                   push eax
// 0080b020  ff157cee8900         call dword ptr [0x89ee7c]
// 0080b026  5e                   pop esi
// 0080b027  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnKillFocus@CXTButton@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
