// from server: 100% by auto
// roc 2011-06 008e6060  unit: CXTColorHex  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e6060
//
// 008e6060  56                   push esi
// 008e6061  8bf1                 mov esi, ecx
// 008e6063  e85c40f2ff           call 0x80a0c4
// 008e6068  807e5c00             cmp byte ptr [esi + 0x5c], 0
// 008e606c  740d                 je 0x8e607b
// 008e606e  8b06                 mov eax, dword ptr [esi]
// 008e6070  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 008e6076  8bce                 mov ecx, esi
// 008e6078  5e                   pop esi
// 008e6079  ffe2                 jmp edx
// 008e607b  5e                   pop esi
// 008e607c  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?PreSubclassWindow@CXTPColorHex@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Dialog/XTPColorPageStandard.cpp
