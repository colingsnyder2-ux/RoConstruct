// from server: 100% by auto
// roc 2007-03 0066e4b0  unit: seg_00660000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e4b0
//
// 0066e4b0  c70178b67c00         mov dword ptr [ecx], 0x7cb678
// 0066e4b6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066e4b9  85c9                 test ecx, ecx
// 0066e4bb  7407                 je 0x66e4c4
// 0066e4bd  51                   push ecx
// 0066e4be  e8f1fefaff           call 0x61e3b4
// 0066e4c3  59                   pop ecx
// 0066e4c4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
