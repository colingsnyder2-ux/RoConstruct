// from server: 100% by auto
// roc 2009-12 0085a580  unit: CXTThemeManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a580
//
// 0085a580  6810a58500           push 0x85a510
// 0085a585  b970b6b900           mov ecx, 0xb9b670
// 0085a58a  e8ffc30c00           call 0x92698e
// 0085a58f  85c0                 test eax, eax
// 0085a591  7505                 jne 0x85a598
// 0085a593  e97495f9ff           jmp 0x7f3b0c
// 0085a598  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?AfxGetThreadState@@YGPAV_AFX_THREAD_STATE@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
