// from server: 100% by auto
// roc 2009-06 0071bc60  unit: CXTPEdit  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071bc60
//
// 0071bc60  0fb7442404           movzx eax, word ptr [esp + 4]
// 0071bc65  3d25e10000           cmp eax, 0xe125
// 0071bc6a  751b                 jne 0x71bc87
// 0071bc6c  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0071bc6f  6a00                 push 0
// 0071bc71  6a00                 push 0
// 0071bc73  6802030000           push 0x302
// 0071bc78  50                   push eax
// 0071bc79  ff1590ee8900         call dword ptr [0x89ee90]
// 0071bc7f  b801000000           mov eax, 1
// 0071bc84  c20800               ret 8
// 0071bc87  3d22e10000           cmp eax, 0xe122
// 0071bc8c  751b                 jne 0x71bca9
// 0071bc8e  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0071bc91  6a00                 push 0
// 0071bc93  6a00                 push 0
// 0071bc95  6801030000           push 0x301
// 0071bc9a  51                   push ecx
// 0071bc9b  ff1590ee8900         call dword ptr [0x89ee90]
// 0071bca1  b801000000           mov eax, 1
// 0071bca6  c20800               ret 8
// 0071bca9  3d23e10000           cmp eax, 0xe123
// 0071bcae  751b                 jne 0x71bccb
// 0071bcb0  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0071bcb3  6a00                 push 0
// 0071bcb5  6a00                 push 0
// 0071bcb7  6800030000           push 0x300
// 0071bcbc  52                   push edx
// 0071bcbd  ff1590ee8900         call dword ptr [0x89ee90]
// 0071bcc3  b801000000           mov eax, 1
// 0071bcc8  c20800               ret 8
// 0071bccb  33c0                 xor eax, eax
// 0071bccd  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnCommand@CXTPCommandBarEditCtrl@@UAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
