// from server: 100% by auto
// roc 2007-08 00691fa0  unit: CXTThemeManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00691fa0
//
// 00691fa0  68301f6900           push 0x691f30
// 00691fa5  b9708f8c00           mov ecx, 0x8c8f70
// 00691faa  e84f690a00           call 0x7388fe
// 00691faf  85c0                 test eax, eax
// 00691fb1  7505                 jne 0x691fb8
// 00691fb3  e968dff9ff           jmp 0x62ff20
// 00691fb8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
