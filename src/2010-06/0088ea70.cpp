// from server: 100% by auto
// roc 2010-06 0088ea70  unit: CXTColorHex  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088ea70
//
// 0088ea70  56                   push esi
// 0088ea71  8bf1                 mov esi, ecx
// 0088ea73  e8f894f1ff           call 0x7a7f70
// 0088ea78  83f8ff               cmp eax, -1
// 0088ea7b  7506                 jne 0x88ea83
// 0088ea7d  0bc0                 or eax, eax
// 0088ea7f  5e                   pop esi
// 0088ea80  c20400               ret 4
// 0088ea83  8b06                 mov eax, dword ptr [esi]
// 0088ea85  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 0088ea8b  8bce                 mov ecx, esi
// 0088ea8d  ffd2                 call edx
// 0088ea8f  33c0                 xor eax, eax
// 0088ea91  5e                   pop esi
// 0088ea92  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorPageStandard.cpp (function ?OnCreate@CXTColorHex@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorPageStandard.cpp
