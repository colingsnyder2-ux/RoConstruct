// from server: 100% by auto
// roc 2007-08 0063d770  unit: CXTPPaintManager  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063d770
//
// 0063d770  85c9                 test ecx, ecx
// 0063d772  7503                 jne 0x63d777
// 0063d774  33c0                 xor eax, eax
// 0063d776  c3                   ret 
// 0063d777  8b4104               mov eax, dword ptr [ecx + 4]
// 0063d77a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ??BCBitmap@@QBEPAUHBITMAP__@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
