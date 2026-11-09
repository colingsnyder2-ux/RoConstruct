// from server: 100% by auto
// roc 2009-06 0079b140  unit: CXTPResourceManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b140
//
// 0079b140  68b0b07900           push 0x79b0b0
// 0079b145  b9a426a500           mov ecx, 0xa526a4
// 0079b14a  e8d3120b00           call 0x84c422
// 0079b14f  85c0                 test eax, eax
// 0079b151  7505                 jne 0x79b158
// 0079b153  e98cdbf7ff           jmp 0x718ce4
// 0079b158  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
