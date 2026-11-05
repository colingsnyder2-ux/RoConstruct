// from server: 100% by auto
// roc 2007-08 00632de0  unit: PAVCXTPToolBar::?$CArray  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00632de0
//
// 00632de0  6880226300           push 0x632280
// 00632de5  b914938c00           mov ecx, 0x8c9314
// 00632dea  e87b551000           call 0x73836a
// 00632def  85c0                 test eax, eax
// 00632df1  7505                 jne 0x632df8
// 00632df3  e928d1ffff           jmp 0x62ff20
// 00632df8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
