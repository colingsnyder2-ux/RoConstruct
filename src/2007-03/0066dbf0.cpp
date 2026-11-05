// from server: 100% by auto
// roc 2007-03 0066dbf0  unit: seg_00660000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066dbf0
//
// 0066dbf0  6a08                 push 8
// 0066dbf2  e883ce0c00           call 0x73aa7a
// 0066dbf7  85c0                 test eax, eax
// 0066dbf9  7407                 je 0x66dc02
// 0066dbfb  c700b8b17c00         mov dword ptr [eax], 0x7cb1b8
// 0066dc01  c3                   ret 
// 0066dc02  33c0                 xor eax, eax
// 0066dc04  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
