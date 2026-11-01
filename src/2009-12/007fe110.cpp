// from server: 100% by auto
// roc 2009-12 007fe110  unit: CXTPPaintManager  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe110
//
// 007fe110  85c9                 test ecx, ecx
// 007fe112  7503                 jne 0x7fe117
// 007fe114  33c0                 xor eax, eax
// 007fe116  c3                   ret 
// 007fe117  8b4104               mov eax, dword ptr [ecx + 4]
// 007fe11a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ??BCBitmap@@QBEPAUHBITMAP__@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
