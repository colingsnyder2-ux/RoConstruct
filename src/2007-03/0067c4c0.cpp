// from server: 100% by auto
// roc 2007-03 0067c4c0  unit: seg_00670000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067c4c0
//
// 0067c4c0  c701d8d57c00         mov dword ptr [ecx], 0x7cd5d8
// 0067c4c6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0067c4c9  85c9                 test ecx, ecx
// 0067c4cb  7407                 je 0x67c4d4
// 0067c4cd  51                   push ecx
// 0067c4ce  e8e11efaff           call 0x61e3b4
// 0067c4d3  59                   pop ecx
// 0067c4d4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
