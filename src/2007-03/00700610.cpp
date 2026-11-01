// from server: 100% by auto
// roc 2007-03 00700610  unit: seg_00700000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00700610
//
// 00700610  c70118d17d00         mov dword ptr [ecx], 0x7dd118
// 00700616  8b4904               mov ecx, dword ptr [ecx + 4]
// 00700619  85c9                 test ecx, ecx
// 0070061b  7407                 je 0x700624
// 0070061d  51                   push ecx
// 0070061e  ff15ccd07700         call dword ptr [0x77d0cc]
// 00700624  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
