// from server: 100% by auto
// roc 2007-03 00701360  unit: seg_00700000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00701360
//
// 00701360  83ec08               sub esp, 8
// 00701363  8d0424               lea eax, [esp]
// 00701366  50                   push eax
// 00701367  e8a41bffff           call 0x6f2f10
// 0070136c  8b4004               mov eax, dword ptr [eax + 4]
// 0070136f  83c408               add esp, 8
// 00701372  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afximageeditordialog.cpp (function ?GetRowHeight@CMFCImageEditorPaletteBar@@EBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afximageeditordialog.cpp
