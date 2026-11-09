// from server: 100% by auto
// roc 2007-03 00630d30  unit: seg_00630000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00630d30
//
// 00630d30  c701a03b7c00         mov dword ptr [ecx], 0x7c3ba0
// 00630d36  8b4904               mov ecx, dword ptr [ecx + 4]
// 00630d39  85c9                 test ecx, ecx
// 00630d3b  7407                 je 0x630d44
// 00630d3d  51                   push ecx
// 00630d3e  e871d6feff           call 0x61e3b4
// 00630d43  59                   pop ecx
// 00630d44  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
