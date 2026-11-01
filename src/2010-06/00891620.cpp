// from server: 100% by auto
// roc 2010-06 00891620  unit: CXTColorBase  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891620
//
// 00891620  56                   push esi
// 00891621  8bf1                 mov esi, ecx
// 00891623  e8de63f1ff           call 0x7a7a06
// 00891628  807e5400             cmp byte ptr [esi + 0x54], 0
// 0089162c  740d                 je 0x89163b
// 0089162e  8b06                 mov eax, dword ptr [esi]
// 00891630  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 00891636  8bce                 mov ecx, esi
// 00891638  5e                   pop esi
// 00891639  ffe2                 jmp edx
// 0089163b  5e                   pop esi
// 0089163c  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorPageCustom.cpp (function ?PreSubclassWindow@CXTColorBase@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorPageCustom.cpp
