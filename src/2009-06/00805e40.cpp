// from server: 100% by auto
// roc 2009-06 00805e40  unit: CXTPOffice2007Image  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00805e40
//
// 00805e40  83ec08               sub esp, 8
// 00805e43  8d0424               lea eax, [esp]
// 00805e46  50                   push eax
// 00805e47  e824ffffff           call 0x805d70
// 00805e4c  8b4004               mov eax, dword ptr [eax + 4]
// 00805e4f  83c408               add esp, 8
// 00805e52  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
