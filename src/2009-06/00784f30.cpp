// from server: 100% by auto
// roc 2009-06 00784f30  unit: ATL::CRegObject  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00784f30
//
// 00784f30  56                   push esi
// 00784f31  e8d240f9ff           call 0x719008
// 00784f36  8bf0                 mov esi, eax
// 00784f38  85f6                 test esi, esi
// 00784f3a  7430                 je 0x784f6c
// 00784f3c  6af0                 push -0x10
// 00784f3e  56                   push esi
// 00784f3f  ff1558ed8900         call dword ptr [0x89ed58]
// 00784f45  a900000040           test eax, 0x40000000
// 00784f4a  7420                 je 0x784f6c
// 00784f4c  6a00                 push 0
// 00784f4e  6a00                 push 0
// 00784f50  68482a0000           push 0x2a48
// 00784f55  56                   push esi
// 00784f56  ff1590ee8900         call dword ptr [0x89ee90]
// 00784f5c  83f801               cmp eax, 1
// 00784f5f  750b                 jne 0x784f6c
// 00784f61  56                   push esi
// 00784f62  ff1598ee8900         call dword ptr [0x89ee98]
// 00784f68  5e                   pop esi
// 00784f69  c20800               ret 8
// 00784f6c  8bc6                 mov eax, esi
// 00784f6e  5e                   pop esi
// 00784f6f  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnWindowFromPoint@CStandardToolTip@CXTPToolTipContext@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
