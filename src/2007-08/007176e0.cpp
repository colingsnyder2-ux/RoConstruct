// from server: 100% by auto
// roc 2007-08 007176e0  unit: CXTPRibbonControlTab  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007176e0
//
// 007176e0  8b01                 mov eax, dword ptr [ecx]
// 007176e2  8b5070               mov edx, dword ptr [eax + 0x70]
// 007176e5  6a01                 push 1
// 007176e7  ffd2                 call edx
// 007176e9  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?OnUnderlineActivate@CXTPRibbonControlTab@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
