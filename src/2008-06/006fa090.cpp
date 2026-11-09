// from server: 100% by auto
// roc 2008-06 006fa090  unit: CXTPCompatibleDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fa090
//
// 006fa090  6a08                 push 8
// 006fa092  e80d1f0c00           call 0x7bbfa4
// 006fa097  85c0                 test eax, eax
// 006fa099  7407                 je 0x6fa0a2
// 006fa09b  c70060a78500         mov dword ptr [eax], 0x85a760
// 006fa0a1  c3                   ret 
// 006fa0a2  33c0                 xor eax, eax
// 006fa0a4  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
