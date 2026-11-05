// from server: 100% by auto
// roc 2008-06 007a3240  unit: CXTButtonThemeOffice2003  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a3240
//
// 007a3240  c70124f38600         mov dword ptr [ecx], 0x86f324
// 007a3246  8b4904               mov ecx, dword ptr [ecx + 4]
// 007a3249  85c9                 test ecx, ecx
// 007a324b  7407                 je 0x7a3254
// 007a324d  51                   push ecx
// 007a324e  ff15d42c8000         call dword ptr [0x802cd4]
// 007a3254  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
