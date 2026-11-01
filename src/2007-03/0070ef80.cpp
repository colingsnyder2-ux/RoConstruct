// from server: 100% by auto
// roc 2007-03 0070ef80  unit: seg_00700000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070ef80
//
// 0070ef80  c7016ce47d00         mov dword ptr [ecx], 0x7de46c
// 0070ef86  8b4904               mov ecx, dword ptr [ecx + 4]
// 0070ef89  85c9                 test ecx, ecx
// 0070ef8b  7407                 je 0x70ef94
// 0070ef8d  51                   push ecx
// 0070ef8e  e821f4f0ff           call 0x61e3b4
// 0070ef93  59                   pop ecx
// 0070ef94  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
