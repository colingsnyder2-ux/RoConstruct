// from server: 100% by auto
// roc 2009-06 00772a30  unit: CXTPCompatibleDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00772a30
//
// 00772a30  6a08                 push 8
// 00772a32  e893940d00           call 0x84beca
// 00772a37  85c0                 test eax, eax
// 00772a39  7407                 je 0x772a42
// 00772a3b  c700b8b78f00         mov dword ptr [eax], 0x8fb7b8
// 00772a41  c3                   ret 
// 00772a42  33c0                 xor eax, eax
// 00772a44  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
