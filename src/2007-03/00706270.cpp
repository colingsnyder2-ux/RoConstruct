// from server: 100% by auto
// roc 2007-03 00706270  unit: seg_00700000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00706270
//
// 00706270  56                   push esi
// 00706271  8bf1                 mov esi, ecx
// 00706273  e85a84f1ff           call 0x61e6d2
// 00706278  83f8ff               cmp eax, -1
// 0070627b  7506                 jne 0x706283
// 0070627d  0bc0                 or eax, eax
// 0070627f  5e                   pop esi
// 00706280  c20400               ret 4
// 00706283  8b06                 mov eax, dword ptr [esi]
// 00706285  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 0070628b  8bce                 mov ecx, esi
// 0070628d  ffd2                 call edx
// 0070628f  33c0                 xor eax, eax
// 00706291  5e                   pop esi
// 00706292  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnCreate@CXTButton@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
