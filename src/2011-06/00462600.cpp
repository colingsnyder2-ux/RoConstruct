// from server: 100% by auto
// roc 2011-06 00462600  unit: CRobloxApp  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00462600
//
// 00462600  85c9                 test ecx, ecx
// 00462602  7503                 jne 0x462607
// 00462604  33c0                 xor eax, eax
// 00462606  c3                   ret 
// 00462607  8b4104               mov eax, dword ptr [ecx + 4]
// 0046260a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?GetSafeHdc@CDC@@QBEPAUHDC__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
