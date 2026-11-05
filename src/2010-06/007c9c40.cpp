// from server: 100% by auto
// roc 2010-06 007c9c40  unit: CXTPCommandBar  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c9c40
//
// 007c9c40  56                   push esi
// 007c9c41  8bf1                 mov esi, ecx
// 007c9c43  85f6                 test esi, esi
// 007c9c45  7518                 jne 0x7c9c5f
// 007c9c47  68e0a57a00           push 0x7aa5e0
// 007c9c4c  b90062c200           mov ecx, 0xc26200
// 007c9c51  e822311b00           call 0x97cd78
// 007c9c56  85c0                 test eax, eax
// 007c9c58  752d                 jne 0x7c9c87
// 007c9c5a  e8eddffdff           call 0x7a7c4c
// 007c9c5f  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 007c9c65  85c0                 test eax, eax
// 007c9c67  751e                 jne 0x7c9c87
// 007c9c69  68e0a57a00           push 0x7aa5e0
// 007c9c6e  b90062c200           mov ecx, 0xc26200
// 007c9c73  e800311b00           call 0x97cd78
// 007c9c78  85c0                 test eax, eax
// 007c9c7a  7505                 jne 0x7c9c81
// 007c9c7c  e8cbdffdff           call 0x7a7c4c
// 007c9c81  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 007c9c87  5e                   pop esi
// 007c9c88  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetMouseManager@CXTPCommandBars@@QBEPAVCXTPMouseManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
