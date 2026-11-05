// from server: 100% by auto
// roc 2011-06 0085f240  unit: CXTPCompatibleDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f240
//
// 0085f240  6a08                 push 8
// 0085f242  e86bd31600           call 0x9cc5b2
// 0085f247  85c0                 test eax, eax
// 0085f249  7407                 je 0x85f252
// 0085f24b  c70004a8ac00         mov dword ptr [eax], 0xaca804
// 0085f251  c3                   ret 
// 0085f252  33c0                 xor eax, eax
// 0085f254  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ?CreateObject@?$CProcessLocal@V_AFX_MAIL_STATE@@@@SGPAVCNoTrackObject@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
