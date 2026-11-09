// from server: 100% by auto
// roc 2009-12 0084d760  unit: CXTPCompatibleDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084d760
//
// 0084d760  6a08                 push 8
// 0084d762  e8c38c0d00           call 0x92642a
// 0084d767  85c0                 test eax, eax
// 0084d769  7407                 je 0x84d772
// 0084d76b  c70060bc9f00         mov dword ptr [eax], 0x9fbc60
// 0084d771  c3                   ret 
// 0084d772  33c0                 xor eax, eax
// 0084d774  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
