// from server: 100% by auto
// roc 2011-06 00828870  unit: CXTPToolBar  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00828870
//
// 00828870  e8a53e1a00           call 0x9cc71a
// 00828875  85c0                 test eax, eax
// 00828877  7501                 jne 0x82887a
// 00828879  c3                   ret 
// 0082887a  56                   push esi
// 0082887b  57                   push edi
// 0082887c  ff15f819a400         call dword ptr [0xa419f8]
// 00828882  50                   push eax
// 00828883  e8a01afeff           call 0x80a328
// 00828888  8bf0                 mov esi, eax
// 0082888a  85f6                 test esi, esi
// 0082888c  7430                 je 0x8288be
// 0082888e  8b3dec1ba400         mov edi, dword ptr [0xa41bec]
// 00828894  8b4620               mov eax, dword ptr [esi + 0x20]
// 00828897  50                   push eax
// 00828898  ffd7                 call edi
// 0082889a  85c0                 test eax, eax
// 0082889c  7420                 je 0x8288be
// 0082889e  8bce                 mov ecx, esi
// 008288a0  e8a71afeff           call 0x80a34c
// 008288a5  8bf0                 mov esi, eax
// 008288a7  56                   push esi
// 008288a8  e8673e1a00           call 0x9cc714
// 008288ad  50                   push eax
// 008288ae  e8891bfeff           call 0x80a43c
// 008288b3  83c408               add esp, 8
// 008288b6  85c0                 test eax, eax
// 008288b8  7509                 jne 0x8288c3
// 008288ba  85f6                 test esi, esi
// 008288bc  75d6                 jne 0x828894
// 008288be  5f                   pop edi
// 008288bf  33c0                 xor eax, eax
// 008288c1  5e                   pop esi
// 008288c2  c3                   ret 
// 008288c3  5f                   pop edi
// 008288c4  b801000000           mov eax, 1
// 008288c9  5e                   pop esi
// 008288ca  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPToolBar.cpp (function ?IsFloatingFrameFocused@CXTPToolBar@@ABEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPToolBar.cpp
