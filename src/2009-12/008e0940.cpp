// from server: 100% by auto
// roc 2009-12 008e0940  unit: CXTPOffice2007Image  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e0940
//
// 008e0940  83ec08               sub esp, 8
// 008e0943  8d0424               lea eax, [esp]
// 008e0946  50                   push eax
// 008e0947  e824ffffff           call 0x8e0870
// 008e094c  8b4004               mov eax, dword ptr [eax + 4]
// 008e094f  83c408               add esp, 8
// 008e0952  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
