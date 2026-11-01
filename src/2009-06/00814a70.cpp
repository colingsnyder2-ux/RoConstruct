// from server: 100% by auto
// roc 2009-06 00814a70  unit: CXTPRibbonControlTab  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814a70
//
// 00814a70  8b897cffffff         mov ecx, dword ptr [ecx - 0x84]
// 00814a76  e95534faff           jmp 0x7b7ed0
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetPaintManager@CXTPRibbonControlTab@@UBEPAVCXTPTabPaintManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
