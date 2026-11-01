// from server: 100% by auto
// roc 2009-06 0080b150  unit: CXTCaptionButton  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b150
//
// 0080b150  8b442408             mov eax, dword ptr [esp + 8]
// 0080b154  56                   push esi
// 0080b155  57                   push edi
// 0080b156  8bf1                 mov esi, ecx
// 0080b158  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0080b15c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0080b15f  50                   push eax
// 0080b160  51                   push ecx
// 0080b161  6828010000           push 0x128
// 0080b166  52                   push edx
// 0080b167  ff155ced8900         call dword ptr [0x89ed5c]
// 0080b16d  6a00                 push 0
// 0080b16f  8bf8                 mov edi, eax
// 0080b171  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080b174  6a00                 push 0
// 0080b176  50                   push eax
// 0080b177  ff157cee8900         call dword ptr [0x89ee7c]
// 0080b17d  8bc7                 mov eax, edi
// 0080b17f  5f                   pop edi
// 0080b180  5e                   pop esi
// 0080b181  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnUpdateUIState@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
