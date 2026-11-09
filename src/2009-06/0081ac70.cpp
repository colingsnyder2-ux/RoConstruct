// from server: 100% by auto
// roc 2009-06 0081ac70  unit: CXTButtonThemeOffice2003  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0081ac70
//
// 0081ac70  c70164f89000         mov dword ptr [ecx], 0x90f864
// 0081ac76  8b4904               mov ecx, dword ptr [ecx + 4]
// 0081ac79  85c9                 test ecx, ecx
// 0081ac7b  7407                 je 0x81ac84
// 0081ac7d  51                   push ecx
// 0081ac7e  ff1564ed8900         call dword ptr [0x89ed64]
// 0081ac84  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
