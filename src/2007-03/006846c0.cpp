// from server: 100% by auto
// roc 2007-03 006846c0  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006846c0
//
// 006846c0  c701b8e37c00         mov dword ptr [ecx], 0x7ce3b8
// 006846c6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006846c9  85c9                 test ecx, ecx
// 006846cb  7407                 je 0x6846d4
// 006846cd  51                   push ecx
// 006846ce  e8e19cf9ff           call 0x61e3b4
// 006846d3  59                   pop ecx
// 006846d4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
