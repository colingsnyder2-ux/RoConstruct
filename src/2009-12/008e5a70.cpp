// from server: 100% by auto
// roc 2009-12 008e5a70  unit: CXTColorSelectorCtrl  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5a70
//
// 008e5a70  56                   push esi
// 008e5a71  57                   push edi
// 008e5a72  8bf1                 mov esi, ecx
// 008e5a74  e8f9090400           call 0x926472
// 008e5a79  8bf8                 mov edi, eax
// 008e5a7b  81e700000010         and edi, 0x10000000
// 008e5a81  7410                 je 0x8e5a93
// 008e5a83  6a00                 push 0
// 008e5a85  6a00                 push 0
// 008e5a87  6800000010           push 0x10000000
// 008e5a8c  8bce                 mov ecx, esi
// 008e5a8e  e847e5f0ff           call 0x7f3fda
// 008e5a93  8bce                 mov ecx, esi
// 008e5a95  e896e3f0ff           call 0x7f3e30
// 008e5a9a  85ff                 test edi, edi
// 008e5a9c  7410                 je 0x8e5aae
// 008e5a9e  6a00                 push 0
// 008e5aa0  6800000010           push 0x10000000
// 008e5aa5  6a00                 push 0
// 008e5aa7  8bce                 mov ecx, esi
// 008e5aa9  e82ce5f0ff           call 0x7f3fda
// 008e5aae  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008e5ab1  33c0                 xor eax, eax
// 008e5ab3  3944240c             cmp dword ptr [esp + 0xc], eax
// 008e5ab7  6a00                 push 0
// 008e5ab9  0f95c0               setne al
// 008e5abc  6a00                 push 0
// 008e5abe  51                   push ecx
// 008e5abf  8986a4000000         mov dword ptr [esi + 0xa4], eax
// 008e5ac5  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e5acb  5f                   pop edi
// 008e5acc  33c0                 xor eax, eax
// 008e5ace  5e                   pop esi
// 008e5acf  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnSetState@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
