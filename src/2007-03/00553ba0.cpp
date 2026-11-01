// from server: 100% by auto
// roc 2007-03 00553ba0  unit: seg_00550000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00553ba0
//
// 00553ba0  c744240402000000     mov dword ptr [esp + 4], 2
// 00553ba8  e983c30000           jmp 0x55ff30
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorDialog.cpp (function ?Create@CXTPEyeDropper@@UAEHPBD0KABUtagRECT@@PAVCWnd@@IPAUCCreateContext@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorDialog.cpp
