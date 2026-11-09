// from server: 100% by auto
// roc 2007-03 0066f7c0  unit: seg_00660000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066f7c0
//
// 0066f7c0  c70190b67c00         mov dword ptr [ecx], 0x7cb690
// 0066f7c6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066f7c9  85c9                 test ecx, ecx
// 0066f7cb  7407                 je 0x66f7d4
// 0066f7cd  51                   push ecx
// 0066f7ce  e8e1ebfaff           call 0x61e3b4
// 0066f7d3  59                   pop ecx
// 0066f7d4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
