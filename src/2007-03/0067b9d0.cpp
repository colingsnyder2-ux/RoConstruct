// from server: 100% by auto
// roc 2007-03 0067b9d0  unit: seg_00670000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067b9d0
//
// 0067b9d0  6860b96700           push 0x67b960
// 0067b9d5  b98c1e8c00           mov ecx, 0x8c1e8c
// 0067b9da  e849f70b00           call 0x73b128
// 0067b9df  85c0                 test eax, eax
// 0067b9e1  7505                 jne 0x67b9e8
// 0067b9e3  e9c629faff           jmp 0x61e3ae
// 0067b9e8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
