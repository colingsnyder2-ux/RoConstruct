// from server: 100% by auto
// roc 2010-06 008855b0  unit: CXTPTabPaintManager  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008855b0
//
// 008855b0  83b9ac00000000       cmp dword ptr [ecx + 0xac], 0
// 008855b7  7443                 je 0x8855fc
// 008855b9  b803000000           mov eax, 3
// 008855be  0144240c             add dword ptr [esp + 0xc], eax
// 008855c2  01442410             add dword ptr [esp + 0x10], eax
// 008855c6  29442414             sub dword ptr [esp + 0x14], eax
// 008855ca  29442418             sub dword ptr [esp + 0x18], eax
// 008855ce  56                   push esi
// 008855cf  8b742408             mov esi, dword ptr [esp + 8]
// 008855d3  8b06                 mov eax, dword ptr [esi]
// 008855d5  8b5038               mov edx, dword ptr [eax + 0x38]
// 008855d8  6a00                 push 0
// 008855da  8bce                 mov ecx, esi
// 008855dc  ffd2                 call edx
// 008855de  8b06                 mov eax, dword ptr [esi]
// 008855e0  8b5034               mov edx, dword ptr [eax + 0x34]
// 008855e3  68ffffff00           push 0xffffff
// 008855e8  8bce                 mov ecx, esi
// 008855ea  ffd2                 call edx
// 008855ec  8b4e04               mov ecx, dword ptr [esi + 4]
// 008855ef  8d442410             lea eax, [esp + 0x10]
// 008855f3  50                   push eax
// 008855f4  51                   push ecx
// 008855f5  ff15c8ba9e00         call dword ptr [0x9ebac8]
// 008855fb  5e                   pop esi
// 008855fc  c21800               ret 0x18
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabPaintManager.cpp (function ?DrawFocusRect@CXTPTabPaintManager@@MAEXPAVCDC@@PAVCXTPTabManagerItem@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabPaintManager.cpp
