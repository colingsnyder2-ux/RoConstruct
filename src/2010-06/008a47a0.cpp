// from server: 100% by auto
// roc 2010-06 008a47a0  unit: CXTPRibbonControlTab  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a47a0
//
// 008a47a0  8b897cffffff         mov ecx, dword ptr [ecx - 0x84]
// 008a47a6  e9054bfaff           jmp 0x8492b0
// library xtp-13.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetPaintManager@CXTPRibbonControlTab@@UBEPAVCXTPTabPaintManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
