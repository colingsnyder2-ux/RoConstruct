// from server: 100% by auto
// roc 2007-03 006c56e0  unit: seg_006c0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c56e0
//
// 006c56e0  c7016c617d00         mov dword ptr [ecx], 0x7d616c
// 006c56e6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006c56e9  85c9                 test ecx, ecx
// 006c56eb  7407                 je 0x6c56f4
// 006c56ed  51                   push ecx
// 006c56ee  e8c18cf5ff           call 0x61e3b4
// 006c56f3  59                   pop ecx
// 006c56f4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
