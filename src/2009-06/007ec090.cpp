// from server: 100% by auto
// roc 2009-06 007ec090  unit: VCEdit::?$CXTMaskEditT  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ec090
//
// 007ec090  6aff                 push -1
// 007ec092  ff15a8ed8900         call dword ptr [0x89eda8]
// 007ec098  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?NotifyPosNotInRange@?$CXTPMaskEditT@VCEdit@@@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTFlatComboBox.cpp
