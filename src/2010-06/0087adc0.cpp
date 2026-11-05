// from server: 100% by auto
// roc 2010-06 0087adc0  unit: VCEdit::?$CXTMaskEditT  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087adc0
//
// 0087adc0  6aff                 push -1
// 0087adc2  ff15c4bb9e00         call dword ptr [0x9ebbc4]
// 0087adc8  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTBrowseEdit.cpp (function ?NotifyPosNotInRange@?$CXTMaskEditT@VCEdit@@@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTBrowseEdit.cpp
