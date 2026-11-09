// from server: 100% by auto
// roc 2007-03 006b4030  unit: seg_006b0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b4030
//
// 006b4030  c70124467d00         mov dword ptr [ecx], 0x7d4624
// 006b4036  8b4904               mov ecx, dword ptr [ecx + 4]
// 006b4039  85c9                 test ecx, ecx
// 006b403b  7407                 je 0x6b4044
// 006b403d  51                   push ecx
// 006b403e  e871a3f6ff           call 0x61e3b4
// 006b4043  59                   pop ecx
// 006b4044  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
