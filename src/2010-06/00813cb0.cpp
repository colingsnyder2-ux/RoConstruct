// from server: 100% by auto
// roc 2010-06 00813cb0  unit: CXTPToolTipContextToolTip  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00813cb0
//
// 00813cb0  8b442408             mov eax, dword ptr [esp + 8]
// 00813cb4  56                   push esi
// 00813cb5  85c0                 test eax, eax
// 00813cb7  7443                 je 0x813cfc
// 00813cb9  8b4804               mov ecx, dword ptr [eax + 4]
// 00813cbc  8b10                 mov edx, dword ptr [eax]
// 00813cbe  51                   push ecx
// 00813cbf  52                   push edx
// 00813cc0  ff15e0b99e00         call dword ptr [0x9eb9e0]
// 00813cc6  8bf0                 mov esi, eax
// 00813cc8  85f6                 test esi, esi
// 00813cca  7432                 je 0x813cfe
// 00813ccc  6af0                 push -0x10
// 00813cce  56                   push esi
// 00813ccf  ff15fcbb9e00         call dword ptr [0x9ebbfc]
// 00813cd5  a900000040           test eax, 0x40000000
// 00813cda  7422                 je 0x813cfe
// 00813cdc  6a00                 push 0
// 00813cde  6a00                 push 0
// 00813ce0  68482a0000           push 0x2a48
// 00813ce5  56                   push esi
// 00813ce6  ff1554ba9e00         call dword ptr [0x9eba54]
// 00813cec  83f801               cmp eax, 1
// 00813cef  750d                 jne 0x813cfe
// 00813cf1  56                   push esi
// 00813cf2  ff154cba9e00         call dword ptr [0x9eba4c]
// 00813cf8  5e                   pop esi
// 00813cf9  c20800               ret 8
// 00813cfc  33f6                 xor esi, esi
// 00813cfe  8bc6                 mov eax, esi
// 00813d00  5e                   pop esi
// 00813d01  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnWindowFromPoint@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
