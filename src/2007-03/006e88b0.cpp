// from server: 100% by auto
// roc 2007-03 006e88b0  unit: seg_006e0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e88b0
//
// 006e88b0  c701bc9c7d00         mov dword ptr [ecx], 0x7d9cbc
// 006e88b6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e88b9  85c9                 test ecx, ecx
// 006e88bb  7407                 je 0x6e88c4
// 006e88bd  51                   push ecx
// 006e88be  e8f15af3ff           call 0x61e3b4
// 006e88c3  59                   pop ecx
// 006e88c4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
