// from server: 100% by auto
// roc 2010-06 007b4820  unit: CPatchedControlComboBox  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4820
//
// 007b4820  8b01                 mov eax, dword ptr [ecx]
// 007b4822  ffa034020000         jmp dword ptr [eax + 0x234]
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ??_9CXTPControlComboBoxList@@$BCDE@AE)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
