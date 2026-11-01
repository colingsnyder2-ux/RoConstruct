// from server: 100% by auto
// roc 2009-12 008c6c30  unit: VCEdit::?$CXTMaskEditT  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6c30
//
// 008c6c30  6aff                 push -1
// 008c6c32  ff153cca9800         call dword ptr [0x98ca3c]
// 008c6c38  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?NotifyInvalidCharacter@?$CXTPMaskEditT@VCEdit@@@@MAEXDD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTFlatComboBox.cpp
