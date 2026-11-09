// from server: 100% by auto
// roc 2007-03 0068d2e0  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068d2e0
//
// 0068d2e0  c70160007d00         mov dword ptr [ecx], 0x7d0060
// 0068d2e6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0068d2e9  85c9                 test ecx, ecx
// 0068d2eb  7407                 je 0x68d2f4
// 0068d2ed  51                   push ecx
// 0068d2ee  e8c110f9ff           call 0x61e3b4
// 0068d2f3  59                   pop ecx
// 0068d2f4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
