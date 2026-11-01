// from server: 100% by auto
// roc 2007-03 00553ae0  unit: seg_00550000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00553ae0
//
// 00553ae0  c744240401000000     mov dword ptr [esp + 4], 1
// 00553ae8  e943c40000           jmp 0x55ff30
// library mfc-9.0/atlmfc\src\mfc\afxribbonpalettegallery.cpp (function ?OnKey@CMFCRibbonGallery@@MAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonpalettegallery.cpp
