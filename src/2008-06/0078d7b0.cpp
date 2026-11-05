// from server: 100% by auto
// roc 2008-06 0078d7b0  unit: CXTPOffice2007Image  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0078d7b0
//
// 0078d7b0  83ec08               sub esp, 8
// 0078d7b3  8d0424               lea eax, [esp]
// 0078d7b6  50                   push eax
// 0078d7b7  e824ffffff           call 0x78d6e0
// 0078d7bc  8b4004               mov eax, dword ptr [eax + 4]
// 0078d7bf  83c408               add esp, 8
// 0078d7c2  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
