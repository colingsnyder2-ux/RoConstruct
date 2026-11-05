// from server: 100% by auto
// roc 2007-03 00680840  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00680840
//
// 00680840  c701f8e17c00         mov dword ptr [ecx], 0x7ce1f8
// 00680846  8b4904               mov ecx, dword ptr [ecx + 4]
// 00680849  85c9                 test ecx, ecx
// 0068084b  7407                 je 0x680854
// 0068084d  51                   push ecx
// 0068084e  ff15ecee7700         call dword ptr [0x77eeec]
// 00680854  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
