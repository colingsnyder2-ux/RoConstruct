// from server: 100% by auto
// roc 2010-06 0088d3d0  unit: CXTColorHex  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088d3d0
//
// 0088d3d0  56                   push esi
// 0088d3d1  8bf1                 mov esi, ecx
// 0088d3d3  e82ea6f1ff           call 0x7a7a06
// 0088d3d8  807e5c00             cmp byte ptr [esi + 0x5c], 0
// 0088d3dc  740d                 je 0x88d3eb
// 0088d3de  8b06                 mov eax, dword ptr [esi]
// 0088d3e0  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 0088d3e6  8bce                 mov ecx, esi
// 0088d3e8  5e                   pop esi
// 0088d3e9  ffe2                 jmp edx
// 0088d3eb  5e                   pop esi
// 0088d3ec  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorPageStandard.cpp (function ?PreSubclassWindow@CXTColorHex@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorPageStandard.cpp
