// from server: 100% by auto
// roc 2009-12 008f1bc0  unit: CXTPRibbonSystemPopupBarPage  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f1bc0
//
// 008f1bc0  56                   push esi
// 008f1bc1  8bf1                 mov esi, ecx
// 008f1bc3  e80832f5ff           call 0x844dd0
// 008f1bc8  c70654f3a000         mov dword ptr [esi], 0xa0f354
// 008f1bce  c7465444f3a000       mov dword ptr [esi + 0x54], 0xa0f344
// 008f1bd5  c7465ce4f2a000       mov dword ptr [esi + 0x5c], 0xa0f2e4
// 008f1bdc  8bc6                 mov eax, esi
// 008f1bde  5e                   pop esi
// 008f1bdf  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ??0CXTPControlFontComboBoxList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
