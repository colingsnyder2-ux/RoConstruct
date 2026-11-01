// from server: 100% by auto
// roc 2009-12 007f91c0  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f91c0
//
// 007f91c0  8b4108               mov eax, dword ptr [ecx + 8]
// 007f91c3  85c0                 test eax, eax
// 007f91c5  7409                 je 0x7f91d0
// 007f91c7  6a00                 push 0
// 007f91c9  50                   push eax
// 007f91ca  ff1598ca9800         call dword ptr [0x98ca98]
// 007f91d0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?CloseWindow@CXTPControlComboBoxAutoCompleteWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
