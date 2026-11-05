// from server: 100% by auto
// roc 2010-06 008017c0  unit: CXTPCompatibleDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008017c0
//
// 008017c0  6a08                 push 8
// 008017c2  e89fb51700           call 0x97cd66
// 008017c7  85c0                 test eax, eax
// 008017c9  7407                 je 0x8017d2
// 008017cb  c70020ffa500         mov dword ptr [eax], 0xa5ff20
// 008017d1  c3                   ret 
// 008017d2  33c0                 xor eax, eax
// 008017d4  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
