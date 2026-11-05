// from server: 100% by auto
// roc 2009-12 0086e8a0  unit: CXTPResourceManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e8a0
//
// 0086e8a0  6810e88600           push 0x86e810
// 0086e8a5  b9ccbab900           mov ecx, 0xb9bacc
// 0086e8aa  e8df800b00           call 0x92698e
// 0086e8af  85c0                 test eax, eax
// 0086e8b1  7505                 jne 0x86e8b8
// 0086e8b3  e95452f8ff           jmp 0x7f3b0c
// 0086e8b8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
