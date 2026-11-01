// from server: 100% by auto
// roc 2010-06 0089a020  unit: CXTCaptionButton  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a020
//
// 0089a020  56                   push esi
// 0089a021  8bf1                 mov esi, ecx
// 0089a023  e848dff0ff           call 0x7a7f70
// 0089a028  83f8ff               cmp eax, -1
// 0089a02b  7506                 jne 0x89a033
// 0089a02d  0bc0                 or eax, eax
// 0089a02f  5e                   pop esi
// 0089a030  c20400               ret 4
// 0089a033  8b06                 mov eax, dword ptr [esi]
// 0089a035  8b9094010000         mov edx, dword ptr [eax + 0x194]
// 0089a03b  8bce                 mov ecx, esi
// 0089a03d  ffd2                 call edx
// 0089a03f  33c0                 xor eax, eax
// 0089a041  5e                   pop esi
// 0089a042  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButton.cpp (function ?OnCreate@CXTButton@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButton.cpp
