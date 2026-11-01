// from server: 100% by auto
// roc 2011-06 00816870  unit: CXTPPopupBar  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00816870
//
// 00816870  8b01                 mov eax, dword ptr [ecx]
// 00816872  8b90ac010000         mov edx, dword ptr [eax + 0x1ac]
// 00816878  6a01                 push 1
// 0081687a  6a00                 push 0
// 0081687c  ffd2                 call edx
// 0081687e  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControlComboBoxExt.cpp (function ?DelayRedraw@CXTPPopupBar@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControlComboBoxExt.cpp
