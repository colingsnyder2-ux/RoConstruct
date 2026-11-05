// from server: 100% by auto
// roc 2007-03 006a19f0  unit: seg_006a0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006a19f0
//
// 006a19f0  c701fc317d00         mov dword ptr [ecx], 0x7d31fc
// 006a19f6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006a19f9  85c9                 test ecx, ecx
// 006a19fb  7407                 je 0x6a1a04
// 006a19fd  51                   push ecx
// 006a19fe  e8b1c9f7ff           call 0x61e3b4
// 006a1a03  59                   pop ecx
// 006a1a04  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
