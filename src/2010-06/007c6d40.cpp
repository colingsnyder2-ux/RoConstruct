// from server: 100% by auto
// roc 2010-06 007c6d40  unit: CXTPToolBar  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c6d40
//
// 007c6d40  55                   push ebp
// 007c6d41  8be9                 mov ebp, ecx
// 007c6d43  e82812feff           call 0x7a7f70
// 007c6d48  85c0                 test eax, eax
// 007c6d4a  7504                 jne 0x7c6d50
// 007c6d4c  5d                   pop ebp
// 007c6d4d  c20400               ret 4
// 007c6d50  57                   push edi
// 007c6d51  8bcd                 mov ecx, ebp
// 007c6d53  e886601b00           call 0x97cdde
// 007c6d58  a900010000           test eax, 0x100
// 007c6d5d  747a                 je 0x7c6dd9
// 007c6d5f  8bcd                 mov ecx, ebp
// 007c6d61  e886611b00           call 0x97ceec
// 007c6d66  8bf8                 mov edi, eax
// 007c6d68  85ff                 test edi, edi
// 007c6d6a  7505                 jne 0x7c6d71
// 007c6d6c  5f                   pop edi
// 007c6d6d  5d                   pop ebp
// 007c6d6e  c20400               ret 4
// 007c6d71  53                   push ebx
// 007c6d72  56                   push esi
// 007c6d73  ff155cba9e00         call dword ptr [0x9eba5c]
// 007c6d79  50                   push eax
// 007c6d7a  e8eb0efeff           call 0x7a7c6a
// 007c6d7f  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 007c6d85  8bf0                 mov esi, eax
// 007c6d87  3bfe                 cmp edi, esi
// 007c6d89  742b                 je 0x7c6db6
// 007c6d8b  8b4720               mov eax, dword ptr [edi + 0x20]
// 007c6d8e  50                   push eax
// 007c6d8f  ff15d0b99e00         call dword ptr [0x9eb9d0]
// 007c6d95  50                   push eax
// 007c6d96  e8cf0efeff           call 0x7a7c6a
// 007c6d9b  3bc6                 cmp eax, esi
// 007c6d9d  7513                 jne 0x7c6db2
// 007c6d9f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007c6da2  6a00                 push 0
// 007c6da4  6a40                 push 0x40
// 007c6da6  686d030000           push 0x36d
// 007c6dab  51                   push ecx
// 007c6dac  ffd3                 call ebx
// 007c6dae  85c0                 test eax, eax
// 007c6db0  7504                 jne 0x7c6db6
// 007c6db2  33c0                 xor eax, eax
// 007c6db4  eb05                 jmp 0x7c6dbb
// 007c6db6  b801000000           mov eax, 1
// 007c6dbb  33d2                 xor edx, edx
// 007c6dbd  85c0                 test eax, eax
// 007c6dbf  8b4520               mov eax, dword ptr [ebp + 0x20]
// 007c6dc2  0f94c2               sete dl
// 007c6dc5  6a00                 push 0
// 007c6dc7  8d149504000000       lea edx, [edx*4 + 4]
// 007c6dce  52                   push edx
// 007c6dcf  686d030000           push 0x36d
// 007c6dd4  50                   push eax
// 007c6dd5  ffd3                 call ebx
// 007c6dd7  5e                   pop esi
// 007c6dd8  5b                   pop ebx
// 007c6dd9  5f                   pop edi
// 007c6dda  b801000000           mov eax, 1
// 007c6ddf  5d                   pop ebp
// 007c6de0  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnNcCreate@CXTPPopupBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
