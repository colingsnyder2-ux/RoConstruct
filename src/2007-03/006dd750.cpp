// from server: 100% by auto
// roc 2007-03 006dd750  unit: seg_006d0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dd750
//
// 006dd750  6aff                 push -1
// 006dd752  ff15b0ed7700         call dword ptr [0x77edb0]
// 006dd758  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?NotifyInvalidCharacter@?$CXTPMaskEditT@VCEdit@@@@MAEXDD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTFlatComboBox.cpp
