// from server: 100% by auto
// roc 2007-03 006f25e0  unit: seg_006f0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f25e0
//
// 006f25e0  c701b4b07d00         mov dword ptr [ecx], 0x7db0b4
// 006f25e6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f25e9  85c9                 test ecx, ecx
// 006f25eb  7407                 je 0x6f25f4
// 006f25ed  51                   push ecx
// 006f25ee  ff15ccd07700         call dword ptr [0x77d0cc]
// 006f25f4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
