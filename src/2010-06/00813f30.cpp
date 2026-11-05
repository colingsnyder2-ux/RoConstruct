// from server: 100% by auto
// roc 2010-06 00813f30  unit: CXTPToolTipContextToolTip  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00813f30
//
// 00813f30  56                   push esi
// 00813f31  e83a40f9ff           call 0x7a7f70
// 00813f36  8bf0                 mov esi, eax
// 00813f38  85f6                 test esi, esi
// 00813f3a  7430                 je 0x813f6c
// 00813f3c  6af0                 push -0x10
// 00813f3e  56                   push esi
// 00813f3f  ff15fcbb9e00         call dword ptr [0x9ebbfc]
// 00813f45  a900000040           test eax, 0x40000000
// 00813f4a  7420                 je 0x813f6c
// 00813f4c  6a00                 push 0
// 00813f4e  6a00                 push 0
// 00813f50  68482a0000           push 0x2a48
// 00813f55  56                   push esi
// 00813f56  ff1554ba9e00         call dword ptr [0x9eba54]
// 00813f5c  83f801               cmp eax, 1
// 00813f5f  750b                 jne 0x813f6c
// 00813f61  56                   push esi
// 00813f62  ff154cba9e00         call dword ptr [0x9eba4c]
// 00813f68  5e                   pop esi
// 00813f69  c20800               ret 8
// 00813f6c  8bc6                 mov eax, esi
// 00813f6e  5e                   pop esi
// 00813f6f  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnWindowFromPoint@CStandardToolTip@CXTPToolTipContext@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
