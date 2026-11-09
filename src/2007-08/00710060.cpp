// from server: 100% by auto
// roc 2007-08 00710060  unit: CXTPOffice2007Image  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00710060
//
// 00710060  83ec08               sub esp, 8
// 00710063  8d0424               lea eax, [esp]
// 00710066  50                   push eax
// 00710067  e824ffffff           call 0x70ff90
// 0071006c  8b4004               mov eax, dword ptr [eax + 4]
// 0071006f  83c408               add esp, 8
// 00710072  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
