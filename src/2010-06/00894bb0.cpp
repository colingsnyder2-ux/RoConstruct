// from server: 100% by auto
// roc 2010-06 00894bb0  unit: CXTPOffice2007Image  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00894bb0
//
// 00894bb0  83ec08               sub esp, 8
// 00894bb3  8d0424               lea eax, [esp]
// 00894bb6  50                   push eax
// 00894bb7  e824ffffff           call 0x894ae0
// 00894bbc  8b4004               mov eax, dword ptr [eax + 4]
// 00894bbf  83c408               add esp, 8
// 00894bc2  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
