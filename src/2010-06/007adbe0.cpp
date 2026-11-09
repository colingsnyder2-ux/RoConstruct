// from server: 100% by auto
// roc 2010-06 007adbe0  unit: CXTPPaintManager  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007adbe0
//
// 007adbe0  85c9                 test ecx, ecx
// 007adbe2  7503                 jne 0x7adbe7
// 007adbe4  33c0                 xor eax, eax
// 007adbe6  c3                   ret 
// 007adbe7  8b4104               mov eax, dword ptr [ecx + 4]
// 007adbea  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?GetSafeHdc@CDC@@QBEPAUHDC__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
