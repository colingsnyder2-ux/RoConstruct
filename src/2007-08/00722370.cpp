// from server: 100% by auto
// roc 2007-08 00722370  unit: CXTButtonThemeOffice2003  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00722370
//
// 00722370  c7019c247e00         mov dword ptr [ecx], 0x7e249c
// 00722376  8b4904               mov ecx, dword ptr [ecx + 4]
// 00722379  85c9                 test ecx, ecx
// 0072237b  7407                 je 0x722384
// 0072237d  51                   push ecx
// 0072237e  ff1538ed7700         call dword ptr [0x77ed38]
// 00722384  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
