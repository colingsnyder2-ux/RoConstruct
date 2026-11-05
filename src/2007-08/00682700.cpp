// from server: 100% by auto
// roc 2007-08 00682700  unit: CXTPCompatibleDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00682700
//
// 00682700  6a08                 push 8
// 00682702  e8275c0b00           call 0x73832e
// 00682707  85c0                 test eax, eax
// 00682709  7407                 je 0x682712
// 0068270b  c7008ced7c00         mov dword ptr [eax], 0x7ced8c
// 00682711  c3                   ret 
// 00682712  33c0                 xor eax, eax
// 00682714  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
