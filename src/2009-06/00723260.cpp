// from server: 100% by auto
// roc 2009-06 00723260  unit: RBX::Network::Players::Plugin  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00723260
//
// 00723260  85c9                 test ecx, ecx
// 00723262  7503                 jne 0x723267
// 00723264  33c0                 xor eax, eax
// 00723266  c3                   ret 
// 00723267  8b4104               mov eax, dword ptr [ecx + 4]
// 0072326a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxautohidebutton.cpp (function ?GetSafeHdc@CDC@@QBEPAUHDC__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebutton.cpp
