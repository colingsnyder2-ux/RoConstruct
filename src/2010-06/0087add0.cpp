// from server: 100% by auto
// roc 2010-06 0087add0  unit: VCEdit::?$CXTMaskEditT  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087add0
//
// 0087add0  6aff                 push -1
// 0087add2  ff15c4bb9e00         call dword ptr [0x9ebbc4]
// 0087add8  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTBrowseEdit.cpp (function ?NotifyInvalidCharacter@?$CXTMaskEditT@VCEdit@@@@MAEXDD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTBrowseEdit.cpp
