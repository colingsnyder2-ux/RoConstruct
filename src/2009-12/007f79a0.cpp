// from server: 100% by auto
// roc 2009-12 007f79a0  unit: IIHH::?$CMap  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f79a0
//
// 007f79a0  68b0647f00           push 0x7f64b0
// 007f79a5  b9d0bab900           mov ecx, 0xb9bad0
// 007f79aa  e88dea1200           call 0x92643c
// 007f79af  85c0                 test eax, eax
// 007f79b1  7505                 jne 0x7f79b8
// 007f79b3  e954c1ffff           jmp 0x7f3b0c
// 007f79b8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
