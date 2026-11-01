// from server: 100% by auto
// roc 2011-06 008fd490  unit: CXTPRibbonControlTab  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008fd490
//
// 008fd490  8b897cffffff         mov ecx, dword ptr [ecx - 0x84]
// 008fd496  8b01                 mov eax, dword ptr [ecx]
// 008fd498  8b80ac010000         mov eax, dword ptr [eax + 0x1ac]
// 008fd49e  ffe0                 jmp eax
// library xtp-15.2.1-shared-mfc/Source\Ribbon\XTPRibbonControlTab.cpp (function ?RedrawControl@CXTPRibbonControlTab@@MAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Ribbon/XTPRibbonControlTab.cpp
