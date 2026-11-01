// from server: 100% by auto
// roc 2011-06 008e7720  unit: CXTColorHex  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e7720
//
// 008e7720  56                   push esi
// 008e7721  8bf1                 mov esi, ecx
// 008e7723  e8062ff2ff           call 0x80a62e
// 008e7728  83f8ff               cmp eax, -1
// 008e772b  7506                 jne 0x8e7733
// 008e772d  0bc0                 or eax, eax
// 008e772f  5e                   pop esi
// 008e7730  c20400               ret 4
// 008e7733  8b06                 mov eax, dword ptr [esi]
// 008e7735  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 008e773b  8bce                 mov ecx, esi
// 008e773d  ffd2                 call edx
// 008e773f  33c0                 xor eax, eax
// 008e7741  5e                   pop esi
// 008e7742  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?OnCreate@CXTPColorHex@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Dialog/XTPColorPageStandard.cpp
