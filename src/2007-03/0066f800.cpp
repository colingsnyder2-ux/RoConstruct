// from server: 100% by auto
// roc 2007-03 0066f800  unit: seg_00660000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066f800
//
// 0066f800  c701a8b67c00         mov dword ptr [ecx], 0x7cb6a8
// 0066f806  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066f809  85c9                 test ecx, ecx
// 0066f80b  7407                 je 0x66f814
// 0066f80d  51                   push ecx
// 0066f80e  e8a1ebfaff           call 0x61e3b4
// 0066f813  59                   pop ecx
// 0066f814  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
