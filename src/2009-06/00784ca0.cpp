// from server: 100% by auto
// roc 2009-06 00784ca0  unit: CXTPToolTipContextToolTip  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00784ca0
//
// 00784ca0  8b442408             mov eax, dword ptr [esp + 8]
// 00784ca4  56                   push esi
// 00784ca5  85c0                 test eax, eax
// 00784ca7  7443                 je 0x784cec
// 00784ca9  8b4804               mov ecx, dword ptr [eax + 4]
// 00784cac  8b10                 mov edx, dword ptr [eax]
// 00784cae  51                   push ecx
// 00784caf  52                   push edx
// 00784cb0  ff1534ef8900         call dword ptr [0x89ef34]
// 00784cb6  8bf0                 mov esi, eax
// 00784cb8  85f6                 test esi, esi
// 00784cba  7432                 je 0x784cee
// 00784cbc  6af0                 push -0x10
// 00784cbe  56                   push esi
// 00784cbf  ff1558ed8900         call dword ptr [0x89ed58]
// 00784cc5  a900000040           test eax, 0x40000000
// 00784cca  7422                 je 0x784cee
// 00784ccc  6a00                 push 0
// 00784cce  6a00                 push 0
// 00784cd0  68482a0000           push 0x2a48
// 00784cd5  56                   push esi
// 00784cd6  ff1590ee8900         call dword ptr [0x89ee90]
// 00784cdc  83f801               cmp eax, 1
// 00784cdf  750d                 jne 0x784cee
// 00784ce1  56                   push esi
// 00784ce2  ff1598ee8900         call dword ptr [0x89ee98]
// 00784ce8  5e                   pop esi
// 00784ce9  c20800               ret 8
// 00784cec  33f6                 xor esi, esi
// 00784cee  8bc6                 mov eax, esi
// 00784cf0  5e                   pop esi
// 00784cf1  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnWindowFromPoint@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
