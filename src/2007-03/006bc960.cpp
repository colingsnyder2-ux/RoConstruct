// from server: 100% by auto
// roc 2007-03 006bc960  unit: seg_006b0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bc960
//
// 006bc960  c70104507d00         mov dword ptr [ecx], 0x7d5004
// 006bc966  8b4904               mov ecx, dword ptr [ecx + 4]
// 006bc969  85c9                 test ecx, ecx
// 006bc96b  7407                 je 0x6bc974
// 006bc96d  51                   push ecx
// 006bc96e  e8411af6ff           call 0x61e3b4
// 006bc973  59                   pop ecx
// 006bc974  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
