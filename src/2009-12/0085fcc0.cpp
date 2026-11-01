// from server: 100% by auto
// roc 2009-12 0085fcc0  unit: CXTPToolTipContextToolTip  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085fcc0
//
// 0085fcc0  8b442408             mov eax, dword ptr [esp + 8]
// 0085fcc4  56                   push esi
// 0085fcc5  85c0                 test eax, eax
// 0085fcc7  7443                 je 0x85fd0c
// 0085fcc9  8b4804               mov ecx, dword ptr [eax + 4]
// 0085fccc  8b10                 mov edx, dword ptr [eax]
// 0085fcce  51                   push ecx
// 0085fccf  52                   push edx
// 0085fcd0  ff1528cb9800         call dword ptr [0x98cb28]
// 0085fcd6  8bf0                 mov esi, eax
// 0085fcd8  85f6                 test esi, esi
// 0085fcda  7432                 je 0x85fd0e
// 0085fcdc  6af0                 push -0x10
// 0085fcde  56                   push esi
// 0085fcdf  ff15d8c99800         call dword ptr [0x98c9d8]
// 0085fce5  a900000040           test eax, 0x40000000
// 0085fcea  7422                 je 0x85fd0e
// 0085fcec  6a00                 push 0
// 0085fcee  6a00                 push 0
// 0085fcf0  68482a0000           push 0x2a48
// 0085fcf5  56                   push esi
// 0085fcf6  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0085fcfc  83f801               cmp eax, 1
// 0085fcff  750d                 jne 0x85fd0e
// 0085fd01  56                   push esi
// 0085fd02  ff15bccb9800         call dword ptr [0x98cbbc]
// 0085fd08  5e                   pop esi
// 0085fd09  c20800               ret 8
// 0085fd0c  33f6                 xor esi, esi
// 0085fd0e  8bc6                 mov eax, esi
// 0085fd10  5e                   pop esi
// 0085fd11  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnWindowFromPoint@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
