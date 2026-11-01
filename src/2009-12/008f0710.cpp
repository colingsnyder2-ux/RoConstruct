// from server: 100% by auto
// roc 2009-12 008f0710  unit: CXTPRibbonControlTab  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f0710
//
// 008f0710  8b01                 mov eax, dword ptr [ecx]
// 008f0712  8b5070               mov edx, dword ptr [eax + 0x70]
// 008f0715  6a01                 push 1
// 008f0717  ffd2                 call edx
// 008f0719  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?OnUnderlineActivate@CXTPRibbonControlTab@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
