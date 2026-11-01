// from server: 100% by auto
// roc 2009-12 007f9e10  unit: CXTPEdit  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9e10
//
// 007f9e10  0fb7442404           movzx eax, word ptr [esp + 4]
// 007f9e15  3d25e10000           cmp eax, 0xe125
// 007f9e1a  751b                 jne 0x7f9e37
// 007f9e1c  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007f9e1f  6a00                 push 0
// 007f9e21  6a00                 push 0
// 007f9e23  6802030000           push 0x302
// 007f9e28  50                   push eax
// 007f9e29  ff15c4cb9800         call dword ptr [0x98cbc4]
// 007f9e2f  b801000000           mov eax, 1
// 007f9e34  c20800               ret 8
// 007f9e37  3d22e10000           cmp eax, 0xe122
// 007f9e3c  751b                 jne 0x7f9e59
// 007f9e3e  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007f9e41  6a00                 push 0
// 007f9e43  6a00                 push 0
// 007f9e45  6801030000           push 0x301
// 007f9e4a  51                   push ecx
// 007f9e4b  ff15c4cb9800         call dword ptr [0x98cbc4]
// 007f9e51  b801000000           mov eax, 1
// 007f9e56  c20800               ret 8
// 007f9e59  3d23e10000           cmp eax, 0xe123
// 007f9e5e  751b                 jne 0x7f9e7b
// 007f9e60  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007f9e63  6a00                 push 0
// 007f9e65  6a00                 push 0
// 007f9e67  6800030000           push 0x300
// 007f9e6c  52                   push edx
// 007f9e6d  ff15c4cb9800         call dword ptr [0x98cbc4]
// 007f9e73  b801000000           mov eax, 1
// 007f9e78  c20800               ret 8
// 007f9e7b  33c0                 xor eax, eax
// 007f9e7d  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnCommand@CXTPCommandBarEditCtrl@@UAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
