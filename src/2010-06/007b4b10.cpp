// from server: 100% by auto
// roc 2010-06 007b4b10  unit: CXTPEdit  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4b10
//
// 007b4b10  0fb7442404           movzx eax, word ptr [esp + 4]
// 007b4b15  3d25e10000           cmp eax, 0xe125
// 007b4b1a  751b                 jne 0x7b4b37
// 007b4b1c  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007b4b1f  6a00                 push 0
// 007b4b21  6a00                 push 0
// 007b4b23  6802030000           push 0x302
// 007b4b28  50                   push eax
// 007b4b29  ff1554ba9e00         call dword ptr [0x9eba54]
// 007b4b2f  b801000000           mov eax, 1
// 007b4b34  c20800               ret 8
// 007b4b37  3d22e10000           cmp eax, 0xe122
// 007b4b3c  751b                 jne 0x7b4b59
// 007b4b3e  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007b4b41  6a00                 push 0
// 007b4b43  6a00                 push 0
// 007b4b45  6801030000           push 0x301
// 007b4b4a  51                   push ecx
// 007b4b4b  ff1554ba9e00         call dword ptr [0x9eba54]
// 007b4b51  b801000000           mov eax, 1
// 007b4b56  c20800               ret 8
// 007b4b59  3d23e10000           cmp eax, 0xe123
// 007b4b5e  751b                 jne 0x7b4b7b
// 007b4b60  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007b4b63  6a00                 push 0
// 007b4b65  6a00                 push 0
// 007b4b67  6800030000           push 0x300
// 007b4b6c  52                   push edx
// 007b4b6d  ff1554ba9e00         call dword ptr [0x9eba54]
// 007b4b73  b801000000           mov eax, 1
// 007b4b78  c20800               ret 8
// 007b4b7b  33c0                 xor eax, eax
// 007b4b7d  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnCommand@CXTPCommandBarEditCtrl@@UAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
