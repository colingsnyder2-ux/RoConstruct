// from server: 100% by auto
// roc 2012-06 009d7650  unit: CXTPCompatibleDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d7650
//
// 009d7650  6a08                 push 8
// 009d7652  e8151f0c00           call 0xa9956c
// 009d7657  85c0                 test eax, eax
// 009d7659  7407                 je 0x9d7662
// 009d765b  c700fc5ec100         mov dword ptr [eax], 0xc15efc
// 009d7661  c3                   ret 
// 009d7662  33c0                 xor eax, eax
// 009d7664  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
