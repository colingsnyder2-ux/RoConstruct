// from server: 100% by auto
// roc 2007-03 0067e8e0  unit: seg_00670000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067e8e0
//
// 0067e8e0  c701dcda7c00         mov dword ptr [ecx], 0x7cdadc
// 0067e8e6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0067e8e9  85c9                 test ecx, ecx
// 0067e8eb  7407                 je 0x67e8f4
// 0067e8ed  51                   push ecx
// 0067e8ee  e8c1faf9ff           call 0x61e3b4
// 0067e8f3  59                   pop ecx
// 0067e8f4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
