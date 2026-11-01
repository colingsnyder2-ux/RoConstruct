// from server: 100% by auto
// roc 2009-06 0080af80  unit: CXTCaptionButton  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080af80
//
// 0080af80  56                   push esi
// 0080af81  57                   push edi
// 0080af82  8bf1                 mov esi, ecx
// 0080af84  e8530f0400           call 0x84bedc
// 0080af89  8bf8                 mov edi, eax
// 0080af8b  81e700000010         and edi, 0x10000000
// 0080af91  7410                 je 0x80afa3
// 0080af93  6a00                 push 0
// 0080af95  6a00                 push 0
// 0080af97  6800000010           push 0x10000000
// 0080af9c  8bce                 mov ecx, esi
// 0080af9e  e80fe2f0ff           call 0x7191b2
// 0080afa3  8bce                 mov ecx, esi
// 0080afa5  e85ee0f0ff           call 0x719008
// 0080afaa  85ff                 test edi, edi
// 0080afac  7410                 je 0x80afbe
// 0080afae  6a00                 push 0
// 0080afb0  6800000010           push 0x10000000
// 0080afb5  6a00                 push 0
// 0080afb7  8bce                 mov ecx, esi
// 0080afb9  e8f4e1f0ff           call 0x7191b2
// 0080afbe  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080afc1  33c0                 xor eax, eax
// 0080afc3  3944240c             cmp dword ptr [esp + 0xc], eax
// 0080afc7  6a00                 push 0
// 0080afc9  0f95c0               setne al
// 0080afcc  6a00                 push 0
// 0080afce  51                   push ecx
// 0080afcf  8986a4000000         mov dword ptr [esi + 0xa4], eax
// 0080afd5  ff157cee8900         call dword ptr [0x89ee7c]
// 0080afdb  5f                   pop edi
// 0080afdc  33c0                 xor eax, eax
// 0080afde  5e                   pop esi
// 0080afdf  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnSetState@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
