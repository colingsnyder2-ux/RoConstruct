// from server: 100% by auto
// roc 2007-03 0067d900  unit: seg_00670000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067d900
//
// 0067d900  56                   push esi
// 0067d901  e8cc0dfaff           call 0x61e6d2
// 0067d906  8bf0                 mov esi, eax
// 0067d908  85f6                 test esi, esi
// 0067d90a  7430                 je 0x67d93c
// 0067d90c  6af0                 push -0x10
// 0067d90e  56                   push esi
// 0067d90f  ff1504ed7700         call dword ptr [0x77ed04]
// 0067d915  a900000040           test eax, 0x40000000
// 0067d91a  7420                 je 0x67d93c
// 0067d91c  6a00                 push 0
// 0067d91e  6a00                 push 0
// 0067d920  68482a0000           push 0x2a48
// 0067d925  56                   push esi
// 0067d926  ff1550ee7700         call dword ptr [0x77ee50]
// 0067d92c  83f801               cmp eax, 1
// 0067d92f  750b                 jne 0x67d93c
// 0067d931  56                   push esi
// 0067d932  ff15c8ec7700         call dword ptr [0x77ecc8]
// 0067d938  5e                   pop esi
// 0067d939  c20800               ret 8
// 0067d93c  8bc6                 mov eax, esi
// 0067d93e  5e                   pop esi
// 0067d93f  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnWindowFromPoint@CStandardToolTip@CXTPToolTipContext@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
