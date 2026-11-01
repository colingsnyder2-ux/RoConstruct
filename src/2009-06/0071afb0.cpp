// from server: 100% by auto
// roc 2009-06 0071afb0  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071afb0
//
// 0071afb0  8b4108               mov eax, dword ptr [ecx + 8]
// 0071afb3  85c0                 test eax, eax
// 0071afb5  7409                 je 0x71afc0
// 0071afb7  6a00                 push 0
// 0071afb9  50                   push eax
// 0071afba  ff1538ed8900         call dword ptr [0x89ed38]
// 0071afc0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?CloseWindow@CXTPControlComboBoxAutoCompleteWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
