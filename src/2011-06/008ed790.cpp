// from server: 100% by auto
// roc 2011-06 008ed790  unit: CXTPOffice2007Image  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ed790
//
// 008ed790  83ec08               sub esp, 8
// 008ed793  8d0424               lea eax, [esp]
// 008ed796  50                   push eax
// 008ed797  e824ffffff           call 0x8ed6c0
// 008ed79c  8b4004               mov eax, dword ptr [eax + 4]
// 008ed79f  83c408               add esp, 8
// 008ed7a2  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
