// from server: 100% by auto
// roc 2010-06 007b3f90  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3f90
//
// 007b3f90  8b4108               mov eax, dword ptr [ecx + 8]
// 007b3f93  85c0                 test eax, eax
// 007b3f95  7409                 je 0x7b3fa0
// 007b3f97  6a00                 push 0
// 007b3f99  50                   push eax
// 007b3f9a  ff1518bc9e00         call dword ptr [0x9ebc18]
// 007b3fa0  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?CloseWindow@CXTPControlComboBoxAutoCompleteWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
