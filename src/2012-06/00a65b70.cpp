// from server: 100% by auto
// roc 2012-06 00a65b70  unit: CXTPOffice2007Image  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a65b70
//
// 00a65b70  83ec08               sub esp, 8
// 00a65b73  8d0424               lea eax, [esp]
// 00a65b76  50                   push eax
// 00a65b77  e824ffffff           call 0xa65aa0
// 00a65b7c  8b4004               mov eax, dword ptr [eax + 4]
// 00a65b7f  83c408               add esp, 8
// 00a65b82  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
