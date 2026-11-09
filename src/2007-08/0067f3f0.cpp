// from server: 100% by auto
// roc 2007-08 0067f3f0  unit: CXTPControlSelector  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0067f3f0
//
// 0067f3f0  c701f8ea7c00         mov dword ptr [ecx], 0x7ceaf8
// 0067f3f6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0067f3f9  85c9                 test ecx, ecx
// 0067f3fb  7407                 je 0x67f404
// 0067f3fd  51                   push ecx
// 0067f3fe  ff15dcd27700         call dword ptr [0x77d2dc]
// 0067f404  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
