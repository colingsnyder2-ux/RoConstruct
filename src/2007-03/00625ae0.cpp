// from server: 100% by auto
// roc 2007-03 00625ae0  unit: seg_00620000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625ae0
//
// 00625ae0  85c9                 test ecx, ecx
// 00625ae2  7503                 jne 0x625ae7
// 00625ae4  33c0                 xor eax, eax
// 00625ae6  c3                   ret 
// 00625ae7  8b4104               mov eax, dword ptr [ecx + 4]
// 00625aea  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ??BCBitmap@@QBEPAUHBITMAP__@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
