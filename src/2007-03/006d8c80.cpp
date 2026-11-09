// from server: 100% by auto
// roc 2007-03 006d8c80  unit: seg_006d0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d8c80
//
// 006d8c80  c701807d7d00         mov dword ptr [ecx], 0x7d7d80
// 006d8c86  8b4904               mov ecx, dword ptr [ecx + 4]
// 006d8c89  85c9                 test ecx, ecx
// 006d8c8b  7407                 je 0x6d8c94
// 006d8c8d  51                   push ecx
// 006d8c8e  e82157f4ff           call 0x61e3b4
// 006d8c93  59                   pop ecx
// 006d8c94  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
