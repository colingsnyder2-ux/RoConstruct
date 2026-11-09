// from server: 100% by auto
// roc 2007-03 0066ac30  unit: seg_00660000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066ac30
//
// 0066ac30  c701a8ae7c00         mov dword ptr [ecx], 0x7caea8
// 0066ac36  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066ac39  85c9                 test ecx, ecx
// 0066ac3b  7407                 je 0x66ac44
// 0066ac3d  51                   push ecx
// 0066ac3e  ff159cd27700         call dword ptr [0x77d29c]
// 0066ac44  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
