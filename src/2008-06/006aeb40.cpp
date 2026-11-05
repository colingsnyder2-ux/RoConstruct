// from server: 100% by auto
// roc 2008-06 006aeb40  unit: CXTPPaintManager  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006aeb40
//
// 006aeb40  85c9                 test ecx, ecx
// 006aeb42  7503                 jne 0x6aeb47
// 006aeb44  33c0                 xor eax, eax
// 006aeb46  c3                   ret 
// 006aeb47  8b4104               mov eax, dword ptr [ecx + 4]
// 006aeb4a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?GetSafeHdc@CDC@@QBEPAUHDC__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
