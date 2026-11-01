// from server: 100% by auto
// roc 2007-03 006b5cb0  unit: seg_006b0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5cb0
//
// 006b5cb0  c70118497d00         mov dword ptr [ecx], 0x7d4918
// 006b5cb6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006b5cb9  85c9                 test ecx, ecx
// 006b5cbb  7407                 je 0x6b5cc4
// 006b5cbd  51                   push ecx
// 006b5cbe  e8f186f6ff           call 0x61e3b4
// 006b5cc3  59                   pop ecx
// 006b5cc4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
