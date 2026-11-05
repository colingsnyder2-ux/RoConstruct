// from server: 100% by auto
// roc 2010-06 007c7010  unit: CXTPToolBar  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c7010
//
// 007c7010  83ec10               sub esp, 0x10
// 007c7013  56                   push esi
// 007c7014  8bf1                 mov esi, ecx
// 007c7016  85f6                 test esi, esi
// 007c7018  7441                 je 0x7c705b
// 007c701a  837e2000             cmp dword ptr [esi + 0x20], 0
// 007c701e  743b                 je 0x7c705b
// 007c7020  8b06                 mov eax, dword ptr [esi]
// 007c7022  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 007c7028  ffd2                 call edx
// 007c702a  85c0                 test eax, eax
// 007c702c  742d                 je 0x7c705b
// 007c702e  8b4620               mov eax, dword ptr [esi + 0x20]
// 007c7031  50                   push eax
// 007c7032  ff15e8bb9e00         call dword ptr [0x9ebbe8]
// 007c7038  85c0                 test eax, eax
// 007c703a  741f                 je 0x7c705b
// 007c703c  56                   push esi
// 007c703d  8d4c2408             lea ecx, [esp + 8]
// 007c7041  e86a820300           call 0x7ff2b0
// 007c7046  50                   push eax
// 007c7047  ff1544bc9e00         call dword ptr [0x9ebc44]
// 007c704d  85c0                 test eax, eax
// 007c704f  750a                 jne 0x7c705b
// 007c7051  b801000000           mov eax, 1
// 007c7056  5e                   pop esi
// 007c7057  83c410               add esp, 0x10
// 007c705a  c3                   ret 
// 007c705b  33c0                 xor eax, eax
// 007c705d  5e                   pop esi
// 007c705e  83c410               add esp, 0x10
// 007c7061  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPToolBar.cpp (function ?IsWindowVisible@CXTPToolBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPToolBar.cpp
