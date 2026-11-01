// from server: 100% by auto
// roc 2009-06 00814bb0  unit: CXTPRibbonControlTab  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814bb0
//
// 00814bb0  8b01                 mov eax, dword ptr [ecx]
// 00814bb2  8b5070               mov edx, dword ptr [eax + 0x70]
// 00814bb5  6a01                 push 1
// 00814bb7  ffd2                 call edx
// 00814bb9  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?OnUnderlineActivate@CXTPRibbonControlTab@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
