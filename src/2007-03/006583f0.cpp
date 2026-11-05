// from server: 100% by auto
// roc 2007-03 006583f0  unit: seg_00650000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006583f0
//
// 006583f0  c701dc807c00         mov dword ptr [ecx], 0x7c80dc
// 006583f6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006583f9  85c9                 test ecx, ecx
// 006583fb  7407                 je 0x658404
// 006583fd  51                   push ecx
// 006583fe  e8b15ffcff           call 0x61e3b4
// 00658403  59                   pop ecx
// 00658404  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
