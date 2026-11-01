// from server: 100% by auto
// roc 2007-03 0070f8e0  unit: seg_00700000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070f8e0
//
// 0070f8e0  c70184e47d00         mov dword ptr [ecx], 0x7de484
// 0070f8e6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0070f8e9  85c9                 test ecx, ecx
// 0070f8eb  7407                 je 0x70f8f4
// 0070f8ed  51                   push ecx
// 0070f8ee  e8c1eaf0ff           call 0x61e3b4
// 0070f8f3  59                   pop ecx
// 0070f8f4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
