// from server: 100% by auto
// roc 2009-12 008f5950  unit: CXTButtonThemeOffice2003  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f5950
//
// 008f5950  c701d4fca000         mov dword ptr [ecx], 0xa0fcd4
// 008f5956  8b4904               mov ecx, dword ptr [ecx + 4]
// 008f5959  85c9                 test ecx, ecx
// 008f595b  7407                 je 0x8f5964
// 008f595d  51                   push ecx
// 008f595e  ff15f8c99800         call dword ptr [0x98c9f8]
// 008f5964  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
