// from server: 100% by auto
// roc 2007-03 006bce20  unit: seg_006b0000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bce20
//
// 006bce20  6aff                 push -1
// 006bce22  6a00                 push 0
// 006bce24  83c124               add ecx, 0x24
// 006bce27  e8f4e3d9ff           call 0x45b220
// 006bce2c  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ?Clear@CXTPDatePickerDaysCollection@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
