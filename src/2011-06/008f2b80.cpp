// from server: 100% by auto
// roc 2011-06 008f2b80  unit: CXTCaptionButton  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f2b80
//
// 008f2b80  56                   push esi
// 008f2b81  8bf1                 mov esi, ecx
// 008f2b83  e8a67af1ff           call 0x80a62e
// 008f2b88  83f8ff               cmp eax, -1
// 008f2b8b  7506                 jne 0x8f2b93
// 008f2b8d  0bc0                 or eax, eax
// 008f2b8f  5e                   pop esi
// 008f2b90  c20400               ret 4
// 008f2b93  8b06                 mov eax, dword ptr [esi]
// 008f2b95  8b9094010000         mov edx, dword ptr [eax + 0x194]
// 008f2b9b  8bce                 mov ecx, esi
// 008f2b9d  ffd2                 call edx
// 008f2b9f  33c0                 xor eax, eax
// 008f2ba1  5e                   pop esi
// 008f2ba2  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButton.cpp (function ?OnCreate@CXTButton@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButton.cpp
