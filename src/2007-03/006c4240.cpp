// from server: 100% by auto
// roc 2007-03 006c4240  unit: seg_006c0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c4240
//
// 006c4240  c7016c5c7d00         mov dword ptr [ecx], 0x7d5c6c
// 006c4246  8b4904               mov ecx, dword ptr [ecx + 4]
// 006c4249  85c9                 test ecx, ecx
// 006c424b  7407                 je 0x6c4254
// 006c424d  51                   push ecx
// 006c424e  e861a1f5ff           call 0x61e3b4
// 006c4253  59                   pop ecx
// 006c4254  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
