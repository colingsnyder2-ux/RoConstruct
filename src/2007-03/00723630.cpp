// from server: 100% by auto
// roc 2007-03 00723630  unit: seg_00720000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00723630
//
// 00723630  c701bc407e00         mov dword ptr [ecx], 0x7e40bc
// 00723636  8b4904               mov ecx, dword ptr [ecx + 4]
// 00723639  85c9                 test ecx, ecx
// 0072363b  7407                 je 0x723644
// 0072363d  51                   push ecx
// 0072363e  ff15f8ed7700         call dword ptr [0x77edf8]
// 00723644  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/docmapi.cpp
