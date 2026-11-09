// from server: 100% by auto
// roc 2007-08 006b3010  unit: CXTPResourceManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b3010
//
// 006b3010  68802f6b00           push 0x6b2f80
// 006b3015  b93c938c00           mov ecx, 0x8c933c
// 006b301a  e8df580800           call 0x7388fe
// 006b301f  85c0                 test eax, eax
// 006b3021  7505                 jne 0x6b3028
// 006b3023  e9f8cef7ff           jmp 0x62ff20
// 006b3028  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
