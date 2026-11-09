// from server: 100% by auto
// roc 2010-06 008a5d70  unit: CXTPRibbonSystemPopupBarPage  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a5d70
//
// 008a5d70  56                   push esi
// 008a5d71  8bf1                 mov esi, ecx
// 008a5d73  e8e830f5ff           call 0x7f8e60
// 008a5d78  c7064c36a700         mov dword ptr [esi], 0xa7364c
// 008a5d7e  c746543c36a700       mov dword ptr [esi + 0x54], 0xa7363c
// 008a5d85  c7465cdc35a700       mov dword ptr [esi + 0x5c], 0xa735dc
// 008a5d8c  8bc6                 mov eax, esi
// 008a5d8e  5e                   pop esi
// 008a5d8f  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ??0CXTPControlFontComboBoxList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
