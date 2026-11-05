// from server: 100% by auto
// roc 2007-03 00684680  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00684680
//
// 00684680  c701a0e37c00         mov dword ptr [ecx], 0x7ce3a0
// 00684686  8b4904               mov ecx, dword ptr [ecx + 4]
// 00684689  85c9                 test ecx, ecx
// 0068468b  7407                 je 0x684694
// 0068468d  51                   push ecx
// 0068468e  e8219df9ff           call 0x61e3b4
// 00684693  59                   pop ecx
// 00684694  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
