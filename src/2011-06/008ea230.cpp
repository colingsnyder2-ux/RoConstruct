// from server: 100% by auto
// roc 2011-06 008ea230  unit: CXTColorBase  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ea230
//
// 008ea230  56                   push esi
// 008ea231  8bf1                 mov esi, ecx
// 008ea233  e88cfef1ff           call 0x80a0c4
// 008ea238  807e5400             cmp byte ptr [esi + 0x54], 0
// 008ea23c  740d                 je 0x8ea24b
// 008ea23e  8b06                 mov eax, dword ptr [esi]
// 008ea240  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 008ea246  8bce                 mov ecx, esi
// 008ea248  5e                   pop esi
// 008ea249  ffe2                 jmp edx
// 008ea24b  5e                   pop esi
// 008ea24c  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?PreSubclassWindow@CXTPColorBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Dialog/XTPColorPageCustom.cpp
