// from server: 100% by auto
// roc 2007-03 0068c7f0  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068c7f0
//
// 0068c7f0  c70128007d00         mov dword ptr [ecx], 0x7d0028
// 0068c7f6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0068c7f9  85c9                 test ecx, ecx
// 0068c7fb  7407                 je 0x68c804
// 0068c7fd  51                   push ecx
// 0068c7fe  e8b11bf9ff           call 0x61e3b4
// 0068c803  59                   pop ecx
// 0068c804  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
