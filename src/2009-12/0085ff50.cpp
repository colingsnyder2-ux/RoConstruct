// from server: 100% by auto
// roc 2009-12 0085ff50  unit: CXTPControlComboBoxPopupBar  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085ff50
//
// 0085ff50  56                   push esi
// 0085ff51  e8da3ef9ff           call 0x7f3e30
// 0085ff56  8bf0                 mov esi, eax
// 0085ff58  85f6                 test esi, esi
// 0085ff5a  7430                 je 0x85ff8c
// 0085ff5c  6af0                 push -0x10
// 0085ff5e  56                   push esi
// 0085ff5f  ff15d8c99800         call dword ptr [0x98c9d8]
// 0085ff65  a900000040           test eax, 0x40000000
// 0085ff6a  7420                 je 0x85ff8c
// 0085ff6c  6a00                 push 0
// 0085ff6e  6a00                 push 0
// 0085ff70  68482a0000           push 0x2a48
// 0085ff75  56                   push esi
// 0085ff76  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0085ff7c  83f801               cmp eax, 1
// 0085ff7f  750b                 jne 0x85ff8c
// 0085ff81  56                   push esi
// 0085ff82  ff15bccb9800         call dword ptr [0x98cbbc]
// 0085ff88  5e                   pop esi
// 0085ff89  c20800               ret 8
// 0085ff8c  8bc6                 mov eax, esi
// 0085ff8e  5e                   pop esi
// 0085ff8f  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnWindowFromPoint@CStandardToolTip@CXTPToolTipContext@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
