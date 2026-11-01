// from server: 100% by auto
// roc 2007-03 006970f0  unit: seg_00690000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006970f0
//
// 006970f0  c701040f7d00         mov dword ptr [ecx], 0x7d0f04
// 006970f6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006970f9  85c9                 test ecx, ecx
// 006970fb  7407                 je 0x697104
// 006970fd  51                   push ecx
// 006970fe  e8b172f8ff           call 0x61e3b4
// 00697103  59                   pop ecx
// 00697104  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
