// from server: 100% by auto
// roc 2011-06 008d64f0  unit: CXTPTabPaintManager  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d64f0
//
// 008d64f0  83b9ac00000000       cmp dword ptr [ecx + 0xac], 0
// 008d64f7  7443                 je 0x8d653c
// 008d64f9  b803000000           mov eax, 3
// 008d64fe  0144240c             add dword ptr [esp + 0xc], eax
// 008d6502  01442410             add dword ptr [esp + 0x10], eax
// 008d6506  29442414             sub dword ptr [esp + 0x14], eax
// 008d650a  29442418             sub dword ptr [esp + 0x18], eax
// 008d650e  56                   push esi
// 008d650f  8b742408             mov esi, dword ptr [esp + 8]
// 008d6513  8b06                 mov eax, dword ptr [esi]
// 008d6515  8b5038               mov edx, dword ptr [eax + 0x38]
// 008d6518  6a00                 push 0
// 008d651a  8bce                 mov ecx, esi
// 008d651c  ffd2                 call edx
// 008d651e  8b06                 mov eax, dword ptr [esi]
// 008d6520  8b5034               mov edx, dword ptr [eax + 0x34]
// 008d6523  68ffffff00           push 0xffffff
// 008d6528  8bce                 mov ecx, esi
// 008d652a  ffd2                 call edx
// 008d652c  8b4e04               mov ecx, dword ptr [esi + 4]
// 008d652f  8d442410             lea eax, [esp + 0x10]
// 008d6533  50                   push eax
// 008d6534  51                   push ecx
// 008d6535  ff151c1ba400         call dword ptr [0xa41b1c]
// 008d653b  5e                   pop esi
// 008d653c  c21800               ret 0x18
// library xtp-15.2.1-shared-mfc/Source\TabManager\XTPTabPaintManager.cpp (function ?DrawFocusRect@CXTPTabPaintManager@@MAEXPAVCDC@@PAVCXTPTabManagerItem@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/TabManager/XTPTabPaintManager.cpp
