// from server: 100% by auto
// roc 2007-03 00622ca0  unit: seg_00620000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00622ca0
//
// 00622ca0  68300c6200           push 0x620c30
// 00622ca5  b910238c00           mov ecx, 0x8c2310
// 00622caa  e8f57d1100           call 0x73aaa4
// 00622caf  85c0                 test eax, eax
// 00622cb1  7505                 jne 0x622cb8
// 00622cb3  e9f6b6ffff           jmp 0x61e3ae
// 00622cb8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
