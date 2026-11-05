// from server: 100% by auto
// roc 2010-06 007b43d0  unit: CXTPPopupBar  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b43d0
//
// 007b43d0  8b01                 mov eax, dword ptr [ecx]
// 007b43d2  8b90ac010000         mov edx, dword ptr [eax + 0x1ac]
// 007b43d8  6a01                 push 1
// 007b43da  6a00                 push 0
// 007b43dc  ffd2                 call edx
// 007b43de  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControlComboBoxExt.cpp (function ?DelayRedraw@CXTPPopupBar@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControlComboBoxExt.cpp
